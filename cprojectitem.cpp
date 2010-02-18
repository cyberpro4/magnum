#include "cprojectitem.h"

CProjectItem::CProjectItem( CPROJECTITEM_PARAMS ){
    m_label = block->text();
    m_document = document;
    m_blockPointer = block;
    m_lineIndex = block->blockNumber();
    m_parent = parent;
    m_blockNumber = 1;
    m_blockList.append( block );
}

CProjectItem::~CProjectItem(){
    CProjectItem* item;
    foreach( item, m_childList ){
        delete item;
    }
}

QTextBlock* CProjectItem::scan( QTextBlock* b ){

    QTextBlock* block = b;
//        procDef[2] = new QRegExp( "(^[Ss]{1,1}[Tt]{1,1}[rR]{1,1}[uU]{1,1}[cC]{1,1}[ ]+[0-9a-zA-Z_\\[\\], ]+)" );
    return b;
}

bool CProjectItem::isIt( QTextBlock* block ){

}

