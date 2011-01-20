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

#ifndef CPROJECTFUNCTION_H
#define CPROJECTFUNCTION_H

#include "cprojecttype.h"
#include "cprojectitemfactory.h"

class CProjectFunction:public CProjectItem{
#warning INSERIRE I PARAMETRI DEI CPROJECTFUNCTION
public:
    CProjectFunction( CPROJECTITEM_PARAMS );

    QTextBlock* scan( QTextBlock* b );
    static bool isIt( QTextBlock* block );

private:
    CProjectType*           m_returnType;
    QList<CProjectType*>    m_paramsList;

};

#endif // CPROJECTFUNCTION_H
