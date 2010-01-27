#ifndef CMAGNUMWIN_H
#define CMAGNUMWIN_H

#include <QtGui>
#include "ccodeeditor.h"

class CMagnumWin : public QMainWindow {

    Q_OBJECT

private:

    QMenuBar		    m_mainMenu;

    QTabBar		    m_documentTabs;
    QVBoxLayout		    m_documentLayout;
    QList<CCodeEditor*>	    m_editors;

public:
    CMagnumWin();
};

#endif // CMAGNUMWIN_H
