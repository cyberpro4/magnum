#include "cprojectfile.h"

CProjectFile::CProjectFile( QString label, CPROJECTITEM_PARAMS ):CProjectItem( CPROJECTITEM_VARS ){
    m_label = label;
    m_type = CPROJECTITEM_TYPE_FILE;
    qDebug() << "new item file: " << m_label;
    scan( block );
}

QTextBlock* CProjectFile::scan( QTextBlock* b ){
    QTextBlock* block = b;
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

        //qDebug() << block->text() << block->isValid();

        if( !block->isValid() )break;
    }
    qDebug() << "end item: " << m_label;
    return block;
}
