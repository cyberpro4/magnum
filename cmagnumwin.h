#ifndef CMAGNUMWIN_H
#define CMAGNUMWIN_H

#include <QtGui>
#include "cdocument.h"
#include "cfindwindow.h"

class CMagnumWin : public QMainWindow {

    Q_OBJECT

private:

    QToolBar		    m_mainToolbar;

    QMenuBar		    m_mainMenu;

    QTabWidget		    m_documentTabs;
    QList<CDocument*>	    m_documents;

    CFindWindow*             m_findWidget;

public:
    CMagnumWin();
    ~CMagnumWin();

    void    closeEvent(QCloseEvent *eve);

public slots:

    void    newDocument();
    void    loadDocument();
    void    saveCurrentDocument();

    void    closeCurrentDocument();
    void    closeAllDocument();
    void    closeDocument( CDocument* );

    void    currentDocumentChanged( int );
    void    tabClose( int );
    void    testEvent();

};

#endif // CMAGNUMWIN_H
