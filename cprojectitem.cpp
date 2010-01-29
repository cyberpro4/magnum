#include "cprojectitem.h"

CProjectItem::CProjectItem( CPROJECTITEM_PARAMS ){
    m_label = label;
    m_document = document;
    m_blockNumber = blockNumber;
    m_blockPointer = block;
    m_parent = parent;
}

CProjectItem::~CProjectItem( ){
    CProjectItem* item;
    foreach( item, m_childList ){
        delete item;
    }
}

void CProjectItem::scan( CDocument* document, QTextBlock* block ){

}
