#include "cprojectfunction.h"

CProjectFunction::CProjectFunction( CPROJECTITEM_PARAMS ):CProjectItem(CPROJECTITEM_VARS){
    QString s = block->text();
    CPROJECTITEM_REMOVE_STR_COMMENT(s)
    s.remove(QRegExp( "([ \t]*[dD]{1,1}[eE]{1,1}[fF]{1,1}[fF]{1,1}[cC]{1,1}[tT]{1,1}[ \t]*)" ));
    m_label = s;
    m_type = CPROJECTITEM_TYPE_FUNC;
    qDebug() << "new item function: " << m_label;
    scan( block );
}

QTextBlock* CProjectFunction::scan( QTextBlock* b ){
    QRegExp endExpr = QRegExp("[ \t]*[eE]{1,1}[nN]{1,1}[dD]{1,1}[fF]{1,1}[cC]{1,1}[tT]{1,1}[ \t]*");

    QTextBlock* block = b;
    //while( &block->next() != (QTextBlock*)&block->end() ){
    while( block->next().isValid() ){
        m_blockNumber++;
        block = &block->next();

        m_blockList.append( *block );

        if( block->text().contains( endExpr ) ){
            qDebug() << "end item: " << m_label;
            break;
        }

        CProjectItem* pjitem = CProjectItemFactory::buildItem( m_document, block, m_parent );
        if( pjitem!=NULL ){
            m_childList.append( pjitem );
            for( int __i = 0; __i < pjitem->blockNumber()-1; __i++ ){
                m_blockNumber++;
                block = &block->next();
                m_blockList.append( *block );
            }
        }

        if( !block->isValid() )break;
    }

    CMagnum_TextBlock* userData = m_document->blockDataAt( m_blockPointer->blockNumber()+1 );
    userData->setFoldable( block->blockNumber()+1 );

    return block;
}

bool CProjectFunction::isIt( QTextBlock* block ){
    QRegExp startExpr = QRegExp( "([ \t]*[dD]{1,1}[eE]{1,1}[fF]{1,1}[fF]{1,1}[cC]{1,1}[tT]{1,1}[ \t]+[0-9a-zA-Z_\\[\\]]+[ ]+[0-9a-zA-Z_]+[ ]*[\\(]{1}[0-9a-zA-Z_,: ]*[\\)]{1})" );
    QString s = block->text();
    CPROJECTITEM_REMOVE_STR_COMMENT(s)
    return s.contains( startExpr );
}
