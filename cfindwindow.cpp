#include "cfindwindow.h"

CFindWindow::CFindWindow( QWidget* parent ) : QDockWidget( parent ){

    QVBoxLayout*    vbox = new QVBoxLayout();

    vbox->addWidget( &m_whatLine );
    vbox->addWidget( &m_resultsView );
    connect( &m_whatLine , SIGNAL(textChanged(QString)) , this , SLOT(whatChanged(QString)));

    QWidget* temp = new QWidget( );
    temp->setLayout(vbox);
    setWidget(temp);
}

void CFindWindow::whatChanged(const QString & text){
    qDebug() << text;
}
