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

#ifndef CDOCUMENT_H
#define CDOCUMENT_H

#include <QObject>
#include "ccodeeditor.h"
#include "cmagnum_textblock.h"

class CDocument : public QObject {

    Q_OBJECT

private:

    CCodeEditor*    m_editor;
    QFileInfo	    m_fileInfo;
    bool            m_isModified;

public:
    CDocument(const QString& file = "" );
    ~CDocument();

    CCodeEditor*    editor();

    bool    loadFromFile(const QString& );
    bool    saveToFile(const QString& file = "" );

    CMagnum_TextBlock*  blockDataAt(int linenumber);

    const QFileInfo& fileInfo();

};

#endif // CDOCUMENT_H
