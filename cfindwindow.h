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

#ifndef CFINDWINDOW_H
#define CFINDWINDOW_H

#include <QtGui>
#include "cdocument.h"

class CFindWindow_Thread;
class CFindWindow_ListItem;

class CFindWindow : public QDockWidget {

    Q_OBJECT

    friend class CFindWindow_Thread;

protected:

    QLineEdit       m_whatLine;
    QListWidget     m_resultsView;

    CDocument*		    m_target;

    CFindWindow_Thread*	    m_searchThread;
    QLabel		    m_searchInProgress;
    QMovie                  m_searchInProgressMovie;

public:

    CFindWindow(QWidget* );
    ~CFindWindow();

    void setTargetDocument( CDocument* );
    CDocument* targetDocument();

    void    focusFind( QString text = QString() );

signals:

    void clearList();
    void goTo(CDocument* target , int nline );


public slots:

    void resultItemDClicked( QListWidgetItem* );
    void loadMovie(bool on);

    void whatChanged( const QString& );

};

class CFindWindow_ListItem : public QListWidgetItem {

public:

    CDocument*      m_document;
    int             m_lineNumber;

    CFindWindow_ListItem(QListWidget * parent = 0, int type = Type);
    ~CFindWindow_ListItem();
};

class CFindWindow_Thread : public QThread {

    Q_OBJECT

protected:

    CFindWindow*    m_findWindow;

public:

    bool	    m_forceStopSearch;

    CFindWindow_Thread( CFindWindow* wnd );

    void waitForSearchStop();

    void nth_run();
    void run();

signals:

    void loadMovie(bool on);
};

#endif // CFINDWINDOW_H
