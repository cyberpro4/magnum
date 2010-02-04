#ifndef CFINDWINDOW_H
#define CFINDWINDOW_H

#include <QtGui>
#include "cdocument.h"

class CFindWindow : public QDockWidget {

    Q_OBJECT

private:

    QLineEdit       m_whatLine;
    QListWidget     m_resultsView;

    CDocument*	    m_target;

public:

    CFindWindow(QWidget* );

    void setTargetDocument( CDocument* );
    CDocument* targetDocument();

public slots:

    void whatChanged( const QString& );

};

#endif // CFINDWINDOW_H
