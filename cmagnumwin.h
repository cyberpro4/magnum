/**************************************************************************

    Copyright (C) 2011 Claudio Cannat�.

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

#ifndef CMAGNUMWIN_H
#define CMAGNUMWIN_H

#include <QtGui>
#include "cdocument.h"
#include "cfindwindow.h"

#include "cproject.h"

#include "caboutwindow.h"
#include "coptions.h"
#include "copteditor.h"
#include "coptgeneral.h"

#define		SETTINGS_INI_FILENAME	"./config.conf"

class CMagnumWin : public QMainWindow {

    Q_OBJECT

private:

    QShortcut               m_shortcutFind;

    QToolBar		    m_mainToolbar;

    QMenuBar		    m_mainMenu;

    QTabWidget		    m_documentTabs;
    QList<CDocument*>	    m_documents;

    CFindWindow*            m_findWidget;

    QMenu                   m_menuLastOpened;
    QList<QString>          m_lastOpenedFile;
    QString                 m_lastOpenDirectory;

    CAboutWindow*           m_aboutDialog;

    CProject*               m_projectManager;

    QFileSystemWatcher      m_fileSystemNotification;

    void lastOpenedFile_Push( const QString& file );

public:
    CMagnumWin();
    ~CMagnumWin();

    void    closeEvent(QCloseEvent *eve);

    void    dragEnterEvent(QDragEnterEvent *);
    void    dropEvent(QDropEvent *);

public slots:

    void    newDocument();

    // carica un documento, nel caso la stringa sia vuota ( come da
    // predefinito ) aprir� un dialogo
    void    loadDocument( const QString& file = QString("") );

    void    saveCurrentDocument();
    void    saveCurrentDocumentAs();
    void    saveAllDocument();

    void    closeCurrentDocument();
    void    closeAllDocument();
    void    closeDocument( CDocument* );

    void    currentDocumentChanged( int );
    void    tabClose( int );
    void    testEvent();

    void    findWin_goTo(CDocument* target , int nline );

    void    aboutDialog();

    void    loadSettings();
    void    saveSettings();

    void    lastOpened_Action(QAction* );

    void    shortcutFind();

    // For QFileSystemWatcher
    void    fsNotify(QString);

};

#endif // CMAGNUMWIN_H
