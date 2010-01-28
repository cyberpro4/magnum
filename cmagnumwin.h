#ifndef CMAGNUMWIN_H
#define CMAGNUMWIN_H

#include <QtGui>
#include "ccodeeditor.h"

class CMagnumWin : public QMainWindow {

    Q_OBJECT

private:

    QMenuBar		    m_mainMenu;

    QTabWidget		    m_documentTabs;
    QList<CCodeEditor*>	    m_editors;

public:
    CMagnumWin();

public slots:

    void    newDocument( bool );

};

#endif // CMAGNUMWIN_H
