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

#include "cprojectfile.h"

CProjectFile::CProjectFile( QString label, CPROJECTITEM_PARAMS ):CProjectItem( CPROJECTITEM_VARS ){
    m_label = label;
    m_type = CPROJECTITEM_TYPE_FILE;
    qDebug() << "new item file: " << m_label;
    scan( block );
}

QTextBlock* CProjectFile::scan( QTextBlock* b ){
    QTextBlock* block = b;

    QProgressDialog pdia( QWidget::tr( "Processing " ) + m_document->fileInfo().fileName() ,
                          "" , 0 , m_document->editor()->blockCount() );
    pdia.setCancelButton( 0 );
    pdia.show();

    //while( &block->next() != (QTextBlock*)&block->end() ){
    while( block->next().isValid() ){
        m_blockNumber++;
        block = &block->next();

        m_blockList.append( block );

        CProjectItem* pjitem = CProjectItemFactory::buildItem( m_document, block, m_parent );
        if( pjitem!=NULL ){
            m_childList.append( pjitem );
            for( int __i = 0; __i < pjitem->blockNumber()-1; __i++ ){
                m_blockNumber++;
                block = &block->next();
                m_blockList.append( block );
            }
        }

        if( m_blockNumber % 20 == 0 )
            pdia.setValue( m_blockNumber );

        //qDebug() << block->text() << block->isValid();

        if( !block->isValid() )break;
    }
    qDebug() << "end item: " << m_label;
    return block;
}
