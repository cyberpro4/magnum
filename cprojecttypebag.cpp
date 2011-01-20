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

#include "cprojecttypebag.h"

CProjectTypeBag* CProjectTypeBag::m_staticInstance;

CProjectTypeBag::CProjectTypeBag(){
    m_typeList.clear();
    addType( "int" );
    addType( "e6pos" );
    addType( "e6axis" );
    m_staticInstance = this;
}

void CProjectTypeBag::addType( QString s ){
    if( !m_typeList.contains( s.toUpper() ) )
        m_typeList.append( s.toUpper() );
}

QList<QString>* CProjectTypeBag::getTypeList( ){
    return &m_typeList;
}
