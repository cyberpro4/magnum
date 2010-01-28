#include "cmagnumwin.h"

CMagnumWin::CMagnumWin(){

    setCentralWidget( &m_documentTabs );

    QMenu* file = m_mainMenu.addMenu( "File" );
    connect( file->addAction( "New" ) , SIGNAL(triggered( bool )) , this , SLOT(newDocument(bool)) );
    file->addAction( "Exit" );

    setMenuBar( &m_mainMenu );
}

void CMagnumWin::newDocument(bool checked){
    CCodeEditor* codeed = new CCodeEditor();

    m_editors.append( codeed );
    m_documentTabs.addTab( codeed , "NEW" );
}
