#include "cprojectitem.h"

CProjectItem::CProjectItem( CPROJECTITEM_PARAMS ){
    m_label = label;
    m_document = document;
    m_blockPointer = block;
    m_parent = parent;
    m_blockNumber = 0;

    scan( m_document, m_blockPointer );
}

CProjectItem::~CProjectItem(){
    CProjectItem* item;
    foreach( item, m_childList ){
        delete item;
    }
}

void CProjectItem::scan( CDocument* document, QTextBlock* block ){
    while( block != (QTextBlock*)&block->end() ){
        qDebug() << "CProjectItem::scan - new block: " << block->text();
        /*if( block->text() ){

        }*/
        m_blockNumber++;
        block = &block->next();
    }

    //QTextBlock::iterator iter = block->begin();
}
