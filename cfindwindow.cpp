#include "cfindwindow.h"

CFindWindow::CFindWindow( QWidget* parent ) : QDockWidget( parent ){

    QVBoxLayout*    vbox = new QVBoxLayout();

    vbox->addWidget( &m_whatLine );
    vbox->addWidget( &m_resultsView );
    connect( &m_whatLine , SIGNAL(textChanged(QString)) , this , SLOT(whatChanged(QString)));

    QWidget* temp = new QWidget( );
    temp->setLayout(vbox);
    setWidget(temp);

    setWindowTitle( "Search" );
    setAllowedAreas( Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea );

    m_target = 0;
}

CDocument* CFindWindow::targetDocument(){
    return m_target;
}

void CFindWindow::setTargetDocument( CDocument* t ){
    m_target = t;
}

void CFindWindow::whatChanged(const QString & text){
    qDebug() << text;
}
