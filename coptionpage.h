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

#ifndef COPTIONPAGE_H
#define COPTIONPAGE_H

#include <QtGui>

class COptionPage : public QWidget {

    Q_OBJECT

public:
    COptionPage(QWidget *parent = 0);

    virtual void        loadSettings(const QMap<QString,QVariant>& values ){}
    virtual void        saveSettings( QMap<QString,QVariant>& ){}
    virtual QString     getUniqueKey(){ return "NULL"; }

    virtual QPixmap     getLeftBarPixmap(){return QPixmap();}
    virtual QString     getLeftBarDescription(){return "NULL";}

signals:

public slots:

};

#endif // COPTIONPAGE_H
