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

#ifndef COPTEDITOR_H
#define COPTEDITOR_H

#include "coptionpage.h"

class COptEditor : public COptionPage {

protected:

    QComboBox       m_fontFamily;
    QLineEdit       m_fontSize;

public:
    COptEditor();

    QPixmap     getLeftBarPixmap(){ return QPixmap( ":opt_editor" ); }
    QString     getLeftBarDescription(){ return "Editor"; }

    QString     getUniqueKey(){return "COPTEDITOR";}

    void        loadSettings(const QMap<QString, QVariant> &values);
    void        saveSettings(QMap<QString, QVariant> &);
};

#endif // COPTEDITOR_H
