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

#ifndef CMAGNUM_TEXTBLOCK_H
#define CMAGNUM_TEXTBLOCK_H

#include <QDebug>
#include <QTextBlock>
#include <QTextBlockUserData>

class CMagnum_TextBlock : public QTextBlockUserData {

private:

    int             m_foldable;
    int             m_parentFold;
    QTextBlock      m_blockPointer;

public:
    CMagnum_TextBlock( QTextBlock );
    ~CMagnum_TextBlock();

    void    setFoldable(int last_line);
    int     foldable();

    int     parentFold();

public:

    static CMagnum_TextBlock* getDataByBlock( QTextBlock* );

};

#endif // CMAGNUM_TEXTBLOCK_H
