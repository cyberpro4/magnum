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

#include "copteditor.h"

COptEditor::COptEditor(){
    QVBoxLayout*    mainvb = new QVBoxLayout();

    QGroupBox*  gb_font = new QGroupBox("Font" );
    QHBoxLayout*    hboxlay = new QHBoxLayout();

    hboxlay->addWidget( &m_fontFamily );
    hboxlay->addWidget( &m_fontSize );

    gb_font->setLayout( hboxlay );

    mainvb->addWidget( gb_font );

    setLayout( mainvb );
}

void COptEditor::loadSettings(const QMap<QString, QVariant> &values){

}

void COptEditor::saveSettings(QMap<QString, QVariant> &){

}
