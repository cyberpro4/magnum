#include "cflowpointeritem.h"

CFlowPointerItem::CFlowPointerItem( CProjectItem* projectItem, int callLine ){  //:QGroupBox( projectItem->label() ){

    QString label;
    if( projectItem->itemType() == CPROJECTITEM_TYPE_PROC ){
        label = ((CProjectProcedure*)projectItem)->getProcedureName();
    }else if( projectItem->itemType() == CPROJECTITEM_TYPE_FUNC ){
        label = ((CProjectFunction*)projectItem)->getFunctionName();
    }
    this->setTitle( label );

    m_projectItem = projectItem;
    m_label = label;
    m_startLine = m_projectItem->firstLineIndex();
    m_endLine = m_projectItem->firstLineIndex() + m_projectItem->blockNumber();
    m_callLine = callLine;
    /*this->setLineWidth( 3 );
    this->setFrameStyle( QFrame::StyledPanel|QFrame::HLine|QFrame::VLine );*/

    QVBoxLayout* mainLayout = new QVBoxLayout();
    this->setLayout( mainLayout );
    this->setWindowTitle( m_label );

    this->setMouseTracking( true );

    this->setFont(QFont("Monospace", 7 ,QFont::PreferQuality|QFont::Normal));
    this->setAutoFillBackground(true);
    this->setFlat(true);

    //this->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    this->setCheckable( true );

    this->setMinimumHeight( QFontMetrics(this->font()).height() * 1 );
    this->setMinimumWidth( QFontMetrics(this->font()).averageCharWidth() * (m_label.length()+5) );

    m_activePalette = QPalette(QColor(255,190,50));
    m_callLinePalette = QPalette(QColor(255,40,10));
}


void CFlowPointerItem::checkIfContainsLineNumber( int line, CDocument* doc ){
    if( doc == m_projectItem->document() ){

	m_active = ((line+1) >= m_startLine && (line+1)<= m_endLine);
	if( m_active ){
	    this->setPalette( m_activePalette );
	}else{
	    this->setPalette( m_basePalette );
	}

	if( line == m_callLine ){
	    this->setPalette( m_callLinePalette );
	}
    }

    CFlowPointerItem* item;
    foreach( item, m_childList ){
	item->checkIfContainsLineNumber( line, doc );
    }
}


void CFlowPointerItem::setBasePalette( QPalette p ){
    m_basePalette = p;
}


CProjectItem* CFlowPointerItem::projectItem(){
    return m_projectItem;
}

void CFlowPointerItem::setCheckability( bool checkable ){
    this->setCheckable( checkable );
    CFlowPointerItem* item;
    foreach( item, m_childList ){
        item->setCheckability( checkable );
    }
}

void CFlowPointerItem::updateVisibility(){
    this->setVisible( this->isChecked() );
    CFlowPointerItem* item;
    foreach( item, m_childList ){
        item->updateVisibility();
    }
    this->adjustSize();
}

void CFlowPointerItem::forceVisibility(){
    this->setVisible( true );
    CFlowPointerItem* item;
    foreach( item, m_childList ){
        item->forceVisibility();
    }
    this->adjustSize();
}

void CFlowPointerItem::addChildItem( CFlowPointerItem* child ){
    int red=this->palette().brush(this->backgroundRole()).color().red();
    int green=this->palette().brush(this->backgroundRole()).color().green();
    int blue=this->palette().brush(this->backgroundRole()).color().blue();

    float scaleFactor=(float)4.0f / 3.0f;
    red=(red+1)*scaleFactor;
    green=(green+1)*scaleFactor;
    blue=(blue+1)*scaleFactor;

    child->setPalette(QPalette(QColor(red,green,blue)));
    child->setBasePalette(QPalette(QColor(red,green,blue)));

    m_childList.append( child );
    this->layout()->addWidget( child );
}

int CFlowPointerItem::firstLineNumber(){
    return m_startLine;
}

int CFlowPointerItem::lastLineNumber(){
    return m_endLine;
}

void CFlowPointerItem::mousePressEvent ( QMouseEvent * event ){
    if(event->buttons() & Qt::LeftButton){
        int line = m_startLine + ((double)event->pos().y()/this->height())*( m_endLine- m_startLine );
        if( line > m_endLine ) line = m_endLine;
        if( line < m_startLine ) line = m_startLine;
        line--;

        emit gotoDocumentLine( m_projectItem->document(), line );
    }else if(event->buttons() & Qt::RightButton){
        emit gotoDocumentLine( m_projectItem->document(), m_callLine );
        //call point
    }
}

void CFlowPointerItem::mouseMoveEvent ( QMouseEvent * event ){
    if(event->buttons() & Qt::LeftButton){
        int line = m_startLine + ((double)event->pos().y()/this->height())*( m_endLine- m_startLine );
        if( line > m_endLine ) line = m_endLine;
        if( line < m_startLine ) line = m_startLine;
        line--;

        emit gotoDocumentLine( m_projectItem->document(), line );
    }
}
