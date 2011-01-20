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
