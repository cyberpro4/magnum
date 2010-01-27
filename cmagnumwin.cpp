#include "cmagnumwin.h"

CMagnumWin::CMagnumWin(){

    m_documentTabs.addTab("ASD");

    m_editors.append( new CCodeEditor() );

    m_documentLayout.addWidget( &m_documentTabs );
    m_documentLayout.addWidget( m_editors.at(0) );

    setCentralWidget( m_editors.at(0) );

    QMenu* file = m_mainMenu.addMenu( "File" );
    file->addAction( "New" );
    file->addAction( "Exit" );

    setMenuBar( &m_mainMenu );
}
