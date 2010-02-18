#include "cprojectvariable.h"

CProjectVariable::CProjectVariable( CPROJECTITEM_PARAMS ):CProjectItem( CPROJECTITEM_VARS ){
    //m_type = type;

    QString s = block->text();
    CPROJECTITEM_REMOVE_STR_COMMENT(s)
    s.remove(QRegExp( CPROJECTITEM_REGEXPR_DECL ));
    s.remove(QRegExp( CPROJECTITEM_REGEXPR_TYPE ));
    s.remove(QRegExp( CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB ));
    m_label = s;
    m_type = CPROJECTITEM_TYPE_VAR;
    qDebug() << "new item variabile: " << m_label;
    //scan( block );

#warning CProjectVariable::CProjectVariable SPLITTARE DICHIARAZIONI MULTIPLE SU SINGOLA LINEA DIVISE DA VIRGOLA
}

bool CProjectVariable::isIt( QTextBlock* block ){

    QString type;
    foreach( type, *CProjectTypeBag::m_staticInstance->getTypeList() ){
        QString declVar = CPROJECTITEM_REGEXPR_DECL;
        int __i=0;
        for( __i = 0; __i < type.size(); __i++ ){
            declVar += QString("[%1%2]").arg(type.at(__i).toLower()).arg(type.at(__i).toUpper());
        }
        declVar += CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB + CPROJECTITEM_REGEXPR_VARNAME;

        QRegExp startExpr = QRegExp( declVar );
        QString s = block->text();
        CPROJECTITEM_REMOVE_STR_COMMENT(s)
        if( s.contains( startExpr ) ){
            return true;
        }
    }
    return false;
}
