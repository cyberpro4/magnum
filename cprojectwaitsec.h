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

#ifndef CPROJECTWAITSEC_H
#define CPROJECTWAITSEC_H

#include "cprojectitem.h"

#define CPROJECTITEM_REGEXPR_WAIT                QString("[Ww]{1}[Aa]{1}[Ii]{1}[Tt]{1}")
#define CPROJECTITEM_REGEXPR_SEC                 QString("[Ss]{1}[Ee]{1}[Cc]{1}")
#define CPROJECTITEM_REGEXPR_WAIT_SEC            CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB+CPROJECTITEM_REGEXPR_WAIT+CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB+CPROJECTITEM_REGEXPR_SEC


class CProjectWaitSec:public CProjectItem{

public:
    CProjectWaitSec(CPROJECTITEM_PARAMS);

    static bool         isIt( QTextBlock* block );

    QString             secs(){ return m_secs; };

private:
    QString       m_secs;

};

#endif // CPROJECTWAITSEC_H
