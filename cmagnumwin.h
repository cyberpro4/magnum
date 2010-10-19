#ifndef CMAGNUMWIN_H
#define CMAGNUMWIN_H

#include <QtGui>
#include "cdocument.h"
#include "cfindwindow.h"

#include "cproject.h"

#include "coptions.h"
#include "copteditor.h"
#include "coptgeneral.h"

#include "ccodecompleter.h"

#define		SETTINGS_INI_FILENAME	"./config.conf"

class CMagnumWin : public QMainWindow {

    Q_OBJECT

private:

    QShortcut               m_shortcutFind;
    QShortcut               m_shortcutCompleteWord;

    QToolBar		    m_mainToolbar;

    QMenuBar		    m_mainMenu;

    QTabWidget		    m_documentTabs;
    QList<CDocument*>	    m_documents;

    CFindWindow*            m_findWidget;

    QMenu                   m_menuLastOpened;
    QList<QString>          m_lastOpenedFile;
    QString                 m_lastOpenDirectory;

    CCodeCompleter          m_codeCompleter;

    CProject*               m_projectManager;

    QFileSystemWatcher      m_fileSystemNotification;

    void lastOpenedFile_Push( const QString& file );

public:
    CMagnumWin();
    ~CMagnumWin();

    void    closeEvent(QCloseEvent *eve);

public slots:

    void    newDocument();

    // carica un documento, nel caso la stringa sia vuota ( come da
    // predefinito ) aprirà un dialogo
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

    void    loadSettings();
    void    saveSettings();

    void    lastOpened_Action(QAction* );

    void    shortcutFind();
    void    shortcutCompleteWord();

    // For QFileSystemWatcher
    void    fsNotify(QString);

};

#endif // CMAGNUMWIN_H
