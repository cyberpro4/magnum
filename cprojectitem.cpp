#include "cprojectitem.h"

CProjectItem::CProjectItem( CPROJECTITEM_PARAMS ){
    m_label = label;
    m_document = document;
    m_blockNumber = blockNumber;
    m_blockPointer = block;
    m_sourceLine = block->text();
}
