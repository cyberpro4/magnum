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

#ifndef COPTIONS_H
#define COPTIONS_H

#include <QtGui>
#include "coptionpage.h"

class COptions_Label : public QWidget {

    Q_OBJECT

private:

    COptionPage*    m_link;
    QLabel          m_description;
    QLabel          m_pixmap;

public:

    COptions_Label( QWidget* );

    void setLink(COptionPage* pg);
    void mouseReleaseEvent(QMouseEvent *ev);

signals:

    void clicked( COptionPage* );

};

class COptions_LeftBar : public QAbstractScrollArea {

private:

    QList<COptions_Label*>   m_items;
    QWidget                  m_mainWidget;
    QVBoxLayout              m_mainWidgetLay;

    int                      m_itemDimension;

public:

    COptions_LeftBar();

    void    addItem( COptionPage* );

    int     itemDimension(){return m_itemDimension;}
    void    setItemDimension(int dim);
};


#define     OPTIONS_FILENAME    "user_options.cfg"

class COptions : public QDialog {

    Q_OBJECT

private:

    COptions_LeftBar        m_leftArea;
    QList<COptionPage*>     m_pages;
    QAbstractScrollArea     m_optArea;

public:

    COptions();
    void    addPage( COptionPage* );

public slots:

    void    pageClicked( COptionPage* );
    void    applyClicked();

};

#endif // COPTIONS_H
