#include "cprojectwaitfor.h"

CProjectWaitFor::CProjectWaitFor( CPROJECTITEM_PARAMS ):CProjectItem( CPROJECTITEM_VARS ){
    QString s = block->text();
    CPROJECTITEM_REMOVE_STR_COMMENT(s)
    s.remove(QRegExp( CPROJECTITEM_REGEXPR_WAIT_FOR ));
    m_condition = s;
    m_label = "WAIT FOR " + s;
    m_type = CPROJECTITEM_TYPE_WFOR;
    qDebug() << "new item wait for: " << m_label;
}

bool CProjectWaitFor::isIt( QTextBlock* block ){

    QRegExp startExpr = QRegExp( CPROJECTITEM_REGEXPR_WAIT_FOR );

    QString s = block->text();
    CPROJECTITEM_REMOVE_STR_COMMENT(s)
    if( s.contains( startExpr ) ){
        return true;
    }

    return false;
}
