#include "cproject.h"

CProject::CProject( QWidget* parent ):QDockWidget( "Project", parent ){
    this->setAllowedAreas( Qt::AllDockWidgetAreas );

    QWidget* mainContainer = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainContainer->setLayout( mainLayout );

    this->setWidget( mainContainer );

    mainLayout->addWidget( &m_treeView );

    m_typeBag = new CProjectTypeBag();

    connect( &m_treeView, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this, SLOT(treeViewItemClicked(QTreeWidgetItem*,int)));
}

void CProject::documentPush( CDocument* document ){
    if( document == NULL )return;

    m_documentMap.insert( document,
                          new CProjectFile(
                                    document->fileInfo().absoluteFilePath(),
                                    document,
                                    &document->editor()->document()->firstBlock(),
                                    NULL )
                        );
    refreshTreeView();
}

void CProject::documentPurge( CDocument* document ){
    CProjectFile* projectFile = m_documentMap.value( document, NULL );
    if( projectFile != NULL ){
        delete projectFile;
        m_documentMap.remove( document );
    }
    refreshTreeView();
}

void CProject::documentChanged(  CDocument* document ){
#warning SVILUPPARE SCAN FILE CProject::documentChanged()
    CProjectFile* projectFile = m_documentMap.value( document, NULL );
    if( projectFile != NULL ){
        delete projectFile;
        m_documentMap.remove( document );
    }
    documentPush( document );
}

void CProject::refreshTreeView(){
    m_treeView.clear();

    const QList<CProjectFile*> fileList = m_documentMap.values();

    CProjectItem* item;
    foreach( item, fileList ){
        CProjectTreeViewItem* newTreeItem = new CProjectTreeViewItem( item, &m_treeView );
        addRecursiveChild( newTreeItem, NULL, item );
    }
}

void CProject::addRecursiveChild( CProjectTreeViewItem* treeParentItem, CProjectTreeViewItem* treeSubItem, CProjectItem* projectItem ){
    if( treeSubItem != NULL )   //NULL se è un nodo principale
        treeParentItem->addChild( treeSubItem );

    QList<CProjectItem*>* itemList = projectItem->childList();
    CProjectItem* subItem;

    foreach( subItem, *itemList ){
        CProjectTreeViewItem* newTreeItem = new CProjectTreeViewItem( subItem );
        addRecursiveChild(
                (treeSubItem!=NULL)?treeSubItem:treeParentItem,
                newTreeItem,
                subItem );
    }
}

void CProject::treeViewItemClicked( QTreeWidgetItem * item, int column ){
    qDebug() << "goto document line: " << ((CProjectTreeViewItem*)item)->projectItem()->firstLineIndex();
    emit gotoDocumentLine(((CProjectTreeViewItem*)item)->projectItem()->document(),
                          ((CProjectTreeViewItem*)item)->projectItem()->firstLineIndex());
}

QMap<CDocument*,CProjectFile*>* CProject::getProjectDocumentMap(){
    return &m_documentMap;
}
