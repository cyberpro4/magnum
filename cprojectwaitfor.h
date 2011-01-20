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

#ifndef CPROJECTWAITFOR_H
#define CPROJECTWAITFOR_H


#include "cprojectitem.h"
#include "cprojectwaitsec.h"

#define CPROJECTITEM_REGEXPR_FOR                 QString("[Ff]{1}[Oo]{1}[Rr]{1}")
#define CPROJECTITEM_REGEXPR_WAIT_FOR            CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB+CPROJECTITEM_REGEXPR_WAIT+CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB+CPROJECTITEM_REGEXPR_FOR+CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB


class CProjectWaitFor:public CProjectItem{

public:
    CProjectWaitFor(CPROJECTITEM_PARAMS);

    static bool         isIt( QTextBlock* block );

    QString             condition(){ return m_condition; }

private:
    QString       m_condition;

};

#endif // CPROJECTWAITFOR_H
