#include "cprojectinterruptdecl.h"

CProjectInterruptDecl::CProjectInterruptDecl( CPROJECTITEM_PARAMS ):CProjectItem( CPROJECTITEM_VARS ){

    QString s = block->text();
    CPROJECTITEM_REMOVE_STR_COMMENT(s)
    s.remove(QRegExp( CPROJECTITEM_REGEXPR_GLOBAL ));
    s.remove(QRegExp( CPROJECTITEM_REGEXPR_INTERRUPT ));
    s.remove(QRegExp( CPROJECTITEM_REGEXPR_DECL ));

    //rimuovo l'id
    m_id = s.left( s.indexOf( QRegExp( CPROJECTITEM_REGEXPR_WHEN) ));
    m_id.remove( QRegExp( CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB ) );

    s = s.right( s.length() - s.indexOf( QRegExp( CPROJECTITEM_REGEXPR_WHEN ) ));
    s.remove(QRegExp( CPROJECTITEM_REGEXPR_WHEN + CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB ));

    m_condition = s.left( s.indexOf( QRegExp(  CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB + CPROJECTITEM_REGEXPR_DO + CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB ) ));
    //m_condition.remove( QRegExp( CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB ) );

    m_call = s.right( s.length() - 3 - s.indexOf( QRegExp( CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB + CPROJECTITEM_REGEXPR_DO + CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB ) ));
    //m_call.remove( QRegExp( CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB ) );


    m_label = "INTERRUPT DECL " + m_id + " WHEN " + m_condition + " DO " + m_call;
    m_type = CPROJECTITEM_TYPE_INTE;
    qDebug() << "new item interrupt: " << m_label;

}

bool CProjectInterruptDecl::isIt( QTextBlock* block ){

    QRegExp startExpr = QRegExp( CPROJECTITEM_REGEXPR_INTERRUPT_DECL );

    QString s = block->text();
    CPROJECTITEM_REMOVE_STR_COMMENT(s)
    if( s.contains( startExpr ) ){
        return true;
    }

    return false;
}
