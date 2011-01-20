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

#include "cmagnum_textblock.h"

CMagnum_TextBlock::CMagnum_TextBlock( QTextBlock p ) {
    m_foldable = -1;
    m_blockPointer = p;
    m_parentFold = -1;
}

CMagnum_TextBlock::~CMagnum_TextBlock() {
}

int CMagnum_TextBlock::parentFold(){
    return m_parentFold;
}

void CMagnum_TextBlock::setFoldable(int last_line){
    m_foldable = last_line;

    QTextBlock blockf = m_blockPointer;

    while( blockf.isValid() && blockf.blockNumber() < last_line ){
        getDataByBlock( &blockf )->m_parentFold = m_blockPointer.blockNumber();
        blockf = blockf.next();
    }
}

CMagnum_TextBlock* CMagnum_TextBlock::getDataByBlock(QTextBlock *b){
    QTextBlockUserData* udata = b->userData();

    if( udata != 0 ){
        CMagnum_TextBlock* mudata = dynamic_cast<CMagnum_TextBlock*>(udata);

        if( mudata != 0 )
            return mudata;

        qDebug() << "OHHHH O_O CHECK HERE!!!";

    } else {

        CMagnum_TextBlock* mudata = new CMagnum_TextBlock( *b );
        b->setUserData( mudata );

        return mudata;
    }

    return 0;
}

int CMagnum_TextBlock::foldable(){
    return m_foldable;
}
