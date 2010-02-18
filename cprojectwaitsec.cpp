#include "cprojectwaitsec.h"

CProjectWaitSec::CProjectWaitSec( CPROJECTITEM_PARAMS ):CProjectItem( CPROJECTITEM_VARS ){
    QString s = block->text();
    CPROJECTITEM_REMOVE_STR_COMMENT(s)
    s.remove(QRegExp( CPROJECTITEM_REGEXPR_WAIT ));
    s.remove(QRegExp( CPROJECTITEM_REGEXPR_SEC ));
    s.remove(QRegExp( CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB ));
    m_secs = s;
    m_label = "WAIT SEC " + s;
    m_type = CPROJECTITEM_TYPE_WSEC;
    qDebug() << "new item wait sec: " << m_label;
}


bool CProjectWaitSec::isIt( QTextBlock* block ){

    QRegExp startExpr = QRegExp( CPROJECTITEM_REGEXPR_WAIT_SEC );

    QString s = block->text();
    CPROJECTITEM_REMOVE_STR_COMMENT(s)
    if( s.contains( startExpr ) ){
        return true;
    }

    return false;
}
