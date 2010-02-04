#ifndef CFINDWINDOW_H
#define CFINDWINDOW_H

#include <QtGui>

class CFindWindow : public QDockWidget {

    Q_OBJECT

private:

    QLineEdit       m_whatLine;
    QListWidget     m_resultsView;

public:

    CFindWindow(QWidget* );

public slots:

    void whatChanged( const QString& );

};

#endif // CFINDWINDOW_H
