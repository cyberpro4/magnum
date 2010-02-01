#include "cprojectprocedure.h"

CProjectProcedure::CProjectProcedure( CPROJECTITEM_PARAMS ):CProjectItem( CPROJECTITEM_VARS ){
    QString s = block->text();
    CPROJECTITEM_REMOVE_STR_COMMENT(s)
    s.remove(QRegExp( "([ ]+[dD]{1,1}[eE]{1,1}[fF]{1,1}[ ]+)" ));
    m_label = s;
    block = scan( block );
}

QTextBlock* CProjectProcedure::scan( QTextBlock* b ){
    QRegExp endExpr = QRegExp("[eE][nN][dD][ ]+");

    QTextBlock* block = b;
    while( block != (QTextBlock*)&block->end() ){
        m_blockList.append( block );

        CProjectItem* pjitem = CProjectItemFactory::buildItem( m_document, block, m_parent );
        if( pjitem!=NULL )
            m_childList.append( pjitem );

        if( block->text().contains( endExpr ) ){
            break;
        }

        m_blockNumber++;
        block = &block->next();
    }
    qDebug() << "end item: " << m_label;
    return block;
}

bool CProjectProcedure::isIt( QTextBlock* block ){
    QRegExp startExpr = QRegExp( "([dD]{1,1}[eE]{1,1}[fF]{1,1}[ ]+[0-9a-zA-Z_]+[ ]*[\\(]{1}[0-9a-zA-Z_:, ]*[\\)]{1})" );
    QString s = block->text();
    CPROJECTITEM_REMOVE_STR_COMMENT(s)
    return s.contains( startExpr );
}
