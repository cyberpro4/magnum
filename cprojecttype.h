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

#ifndef CPROJECTTYPE_H
#define CPROJECTTYPE_H

#include "cprojectitem.h"
#include "cprojecttypebag.h"

/*
"
struct          ([sS][tT][rR][uU][cC]){1}[ \\t]+
nomestrutt      ([0-9_]*[a-zA-Z]+[0-9_]*)+[ \\t]+
tipo            (([0-9_]*[a-zA-Z]+[0-9_]*)+[ \\t]+){1}
nomecampo       ([\\$]{0,1}([0-9_]*[a-zA-Z]+[0-9_]*)+([\\[]{1}[ ]*[0-9]+[ ]*[\\]]{1})*){1}
,altrocampo     ([ \\t]*,([ \\t]*[\\$]{0,1}([0-9_]*[a-zA-Z]+[0-9_]*)+([\\[]{1}[ ]*[0-9]+[ ]*[\\]]{1})*){1})*
da inserire |, tipo altrocampo
"
*/
class CProjectType:public CProjectItem{
public:
    CProjectType( CPROJECTITEM_PARAMS );

};

#endif // CPROJECTTYPE_H
