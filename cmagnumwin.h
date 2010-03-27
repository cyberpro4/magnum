#ifndef CMAGNUMWIN_H
#define CMAGNUMWIN_H

#include <QtGui>
#include "cdocument.h"
#include "cfindwindow.h"

#include "cproject.h"
#include "cflowpointer.h"

#include "coptions.h"
#include "copteditor.h"
#include "coptgeneral.h"

#define		SETTINGS_INI_FILENAME	"./config.conf"

class CMagnumWin : public QMainWindow {

    Q_OBJECT

private:

    QToolBar		    m_mainToolbar;

    QMenuBar		    m_mainMenu;

    QTabWidget		    m_documentTabs;
    QList<CDocument*>	    m_documents;

    CFindWindow*            m_findWidget;

    QMenu                   m_menuLastOpened;
    QList<QString>          m_lastOpenedFile;
    QString                 m_lastOpenDirectory;


    CProject*               m_projectManager;
    CFlowPointer*           m_flowPointer;

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

};

#endif // CMAGNUMWIN_H
