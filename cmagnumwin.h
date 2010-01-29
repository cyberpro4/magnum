#ifndef CMAGNUMWIN_H
#define CMAGNUMWIN_H

#include <QtGui>
#include "cdocument.h"

class CMagnumWin : public QMainWindow {

    Q_OBJECT

private:

    QMenuBar		    m_mainMenu;

    QTabWidget		    m_documentTabs;
    QList<CDocument*>	    m_documents;

public:
    CMagnumWin();

public slots:

    void    newDocument( bool );
    void    loadDocument( bool );
    void    saveCurrentDocument(bool );

};

#endif // CMAGNUMWIN_H
