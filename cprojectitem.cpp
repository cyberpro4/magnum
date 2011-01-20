/**************************************************************************

    Copyright (C) 2011 Claudio Cannatà.

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Magnum.  If not, see <http://www.gnu.org/licenses/>.

**************************************************************************/

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

