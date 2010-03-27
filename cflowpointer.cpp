#include "cflowpointer.h"

CFlowPointer::CFlowPointer( CProject* project, QWidget* parent ):QDockWidget( "Flow pointer", parent ){
    this->setAllowedAreas( Qt::AllDockWidgetAreas );

    QWidget* mainContainer = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainContainer->setLayout( mainLayout );


    QToolBar* tools = new QToolBar( this );
    QAction* action = new QAction( QIcon(":plus"), "Force visibility", tools );
    connect( action, SIGNAL(triggered()), this, SLOT(forceVisibility()) );
    tools->addAction( action );
    mainLayout->addWidget( tools );

    m_rootItem = NULL;
    m_project = project;

    scrollArea = new QScrollArea;
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setWidgetResizable(false);
    ((QWidget*)scrollArea)->setSizePolicy( QSizePolicy::Expanding,QSizePolicy::Expanding );

    mainLayout->addWidget( scrollArea );

    this->setWidget( mainContainer );
}

void CFlowPointer::scanProjectFunctionsItems(){
    m_projectFunctionItems.clear();
    m_projectFunctionItemsRegExpr.clear();

    QMap<CDocument*,CProjectFile*>* projectMap = m_project->getProjectDocumentMap();
    CProjectFile* file;
    foreach( file, projectMap->values() ){
        recursiveScanFunctions( file );
    }
}
QString CFlowPointer::buildProjectItemRegExpr( CProjectItem* item ){
    QString funcName = getProjectItemLabel( item );

    QString stringExpr = QString("[ \\t(,)\\[\\]=]{1}%1[ \\t]*[(]{1}").arg( funcName );
    return stringExpr;
}
void CFlowPointer::recursiveScanFunctions( CProjectItem* item ){
    CProjectItem *it;

    foreach( it, *item->childList() ){

        if( it->itemType() == CPROJECTITEM_TYPE_PROC ){
            m_projectFunctionItems.append( ((CProjectProcedure*)it) );
            m_projectFunctionItemsRegExpr.insert( buildProjectItemRegExpr( it ), it );
        }else if( it->itemType() == CPROJECTITEM_TYPE_FUNC ){
            m_projectFunctionItems.append( ((CProjectFunction*)it) );
            m_projectFunctionItemsRegExpr.insert( buildProjectItemRegExpr( it ), it );
        }


        if( it->childList()->size() > 0 )
            recursiveScanFunctions( it );
    }
}

QString CFlowPointer::getProjectItemLabel( CProjectItem* item ){
    if( item->itemType() == CPROJECTITEM_TYPE_PROC ){
        return ((CProjectProcedure*)item)->getProcedureName();
    }else if( item->itemType() == CPROJECTITEM_TYPE_FUNC ){
        return ((CProjectFunction*)item)->getFunctionName();
    }
}

void CFlowPointer::setCurrentDocument( CDocument* document ){
    scanProjectFunctionsItems();

    //scanna il documento in cerca dei simboli di funzioni e procedure conosciuti nel progetto
    m_currentDocument = document;

    CProjectFile* prjFile = m_project->getProjectDocumentMap()->value( m_currentDocument, NULL );
    if( prjFile != NULL ){
        //CLEAR ALL EXISTING FLOW POINTER ITEMS
        if( m_rootItem != NULL ){
            m_rootItem->hide();
            delete scrollArea->takeWidget();
            m_rootItem = NULL;
        }

        m_rootItem = new CFlowPointerItem( getRootFunction( prjFile ) );
        connect( m_rootItem, SIGNAL(gotoDocumentLine(CDocument*,int)), this, SLOT(gotoDocumentLine(CDocument*,int)) );
        connect( m_rootItem, SIGNAL(toggled(bool)), this, SLOT(updateVisibility()) );
        //<<<<<<<<<<<<<<<COSTRUZIONE DEL FLOW POINTER>>>>>>>>>>>>>>>>>
        recursiveBuildFlowPointerTree( m_rootItem );

        scrollArea->setWidget( m_rootItem );
        scrollArea->ensureWidgetVisible( m_rootItem );

        m_rootItem->show();
    }
}

CProjectItem* CFlowPointer::getRootFunction( CProjectFile* file ){
    CProjectItem *it;

    foreach( it, *file->childList() ){

        if(( it->itemType() == CPROJECTITEM_TYPE_PROC ) || ( it->itemType() == CPROJECTITEM_TYPE_FUNC )){
            return (CProjectProcedure*)it;
        }
    }
    return NULL;
}

void CFlowPointer::recursiveBuildFlowPointerTree( CFlowPointerItem* momItem ){
    qDebug() << "CFlowPointer::recursiveBuildFlowPointerTree -- " << "scanning: " << momItem->projectItem()->label();
    CDocument* document = momItem->projectItem()->document();

    QTextBlock block = document->editor()->document()->findBlockByLineNumber( momItem->firstLineNumber() );
    //while( &block->next() != (QTextBlock*)&block->end() ){

    CProjectItem* prjItem;
    CFlowPointerItem* flowItem;

    while( block.next().isValid() && block.firstLineNumber() < momItem->lastLineNumber() ){
        block = block.next();
        //GET PROJECT ITEM FROM LINE -- CONTROLLA SE LA LINEA CORRENTE CONTIENE UNA CHIAMATA A FUNZIONE VALIDA
        /*if( block.text().contains( endExpr ) ){
            break;
        }*/
        prjItem = getLineContainedProjectItem( block.text() );
        if( prjItem != NULL ){
            flowItem = new CFlowPointerItem( prjItem, block.firstLineNumber() );
            connect( flowItem, SIGNAL(gotoDocumentLine(CDocument*,int)), this, SLOT(gotoDocumentLine(CDocument*,int)) );
            connect( flowItem, SIGNAL(toggled(bool)), this, SLOT(updateVisibility()) );
            momItem->addChildItem( flowItem );
            recursiveBuildFlowPointerTree( flowItem );
        }

        if( !block.isValid() )break;
    }
}

CProjectItem* CFlowPointer::getLineContainedProjectItem( QString lineText ){
    QStringList expressions = m_projectFunctionItemsRegExpr.keys();
    QString expression;
    if( lineText.contains( '(') ){
        CPROJECTITEM_REMOVE_STR_COMMENT(lineText);

        if( lineText.trimmed().length() > 2 );
        foreach( expression, expressions ){
            QRegExp reg( expression, Qt::CaseInsensitive );
            if( reg.indexIn( lineText ) != -1 ){
                return m_projectFunctionItemsRegExpr.value( expression );
            }
        }
    }
    return NULL;
}

void CFlowPointer::gotoDocumentLine( CDocument* document, int line ){
    emit gotoDocumentLinePropagate( document, line );
}

void CFlowPointer::updateVisibility(){
    if( m_rootItem != NULL )
        m_rootItem->updateVisibility();
    //scrollArea->takeWidget();
    //scrollArea->adjustSize();
    //scrollArea->setWidget( m_rootItem );
}

void CFlowPointer::forceVisibility(){
    if( m_rootItem != NULL )
        m_rootItem->forceVisibility();
    //scrollArea->adjustSize();
}
