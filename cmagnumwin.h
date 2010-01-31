#ifndef CMAGNUMWIN_H
#define CMAGNUMWIN_H

#include <QtGui>
#include "cdocument.h"

class CMagnumWin : public QMainWindow {

    Q_OBJECT

private:

    QToolBar		    m_mainToolbar;

    QMenuBar		    m_mainMenu;

    QTabWidget		    m_documentTabs;
    QList<CDocument*>	    m_documents;

public:
    CMagnumWin();

    void    closeEvent(QCloseEvent *eve);

public slots:

    void    newDocument();
    void    loadDocument();
    void    saveCurrentDocument();

    void    testEvent();

};

#endif // CMAGNUMWIN_H
