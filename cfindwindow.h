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

public:

    CFindWindow(QWidget* );
    ~CFindWindow();

    void setTargetDocument( CDocument* );
    CDocument* targetDocument();

signals:

    void clearList();
    void goTo(CDocument* target , int nline );

public slots:

    void resultItemDClicked( QListWidgetItem* );

    void whatChanged( const QString& );

};

class CFindWindow_ListItem : public QListWidgetItem {

public:

    CDocument*      m_document;
    int             m_lineNumber;

    CFindWindow_ListItem(QListWidget * parent = 0, int type = Type);
};

class CFindWindow_Thread : public QThread {

    Q_OBJECT

protected:

    CFindWindow*    m_findWindow;

public:

    bool	    m_forceStopSearch;

    CFindWindow_Thread( CFindWindow* wnd );

    void waitForSearchStop();
    void run();
};

#endif // CFINDWINDOW_H