#include "caboutwindow.h"

CAboutWindow::CAboutWindow( QString iconPathName, QString text, QWidget* parent ):QDialog( parent ){

    m_icon = new QPixmap( iconPathName );
    m_label = new QLabel( text );

    m_iconLabel = new QLabel( );
    m_iconLabel->setPixmap( *m_icon );

    QHBoxLayout* layout =  new QHBoxLayout();
    this->setLayout( layout );

    layout->addWidget( m_iconLabel );
    layout->addWidget( m_label );

}
