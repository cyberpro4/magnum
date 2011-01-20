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
