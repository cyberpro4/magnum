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
