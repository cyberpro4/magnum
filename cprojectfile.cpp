#include "cprojectfile.h"

CProjectFile::CProjectFile( QString label, CPROJECTITEM_PARAMS ):CProjectItem( CPROJECTITEM_VARS ){
    m_label = label;
}

QTextBlock* CProjectFile::scan( QTextBlock* b ){
    QTextBlock* block = b;
    while( block != (QTextBlock*)&block->end() ){
        m_blockList.append( block );
        CProjectItem* pjitem = CProjectItemFactory::buildItem( m_document, block, m_parent );
        if( pjitem!=NULL )
            m_childList.append( pjitem );

        m_blockNumber++;
        block = &block->next();
    }
    qDebug() << "end item: " << m_label;
    return block;
}
