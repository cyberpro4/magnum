#include "cmagnumwin.h"

CMagnumWin::CMagnumWin(){

    setCentralWidget( &m_documentTabs );

    QMenu* file = m_mainMenu.addMenu( "File" );
    connect( file->addAction( "New" ) , SIGNAL(triggered( bool )) , this , SLOT(newDocument(bool)) );
    connect( file->addAction( "Open" ) , SIGNAL(triggered( bool )) , this , SLOT(loadDocument(bool)) );

    setMenuBar( &m_mainMenu );
}

void CMagnumWin::newDocument(bool checked){
    CDocument* doc = new CDocument();

    m_documents.append( doc );
    m_documentTabs.addTab( doc->editor() , "NEW" );
}

void CMagnumWin::loadDocument(bool checked ){

    QString filename = QFileDialog::getOpenFileName( this , "Load from file" , "" , "*.*" );

    if( !filename.isNull() ){
	CDocument* doc = new CDocument( filename );

	m_documentTabs.addTab( doc->editor() , filename );
	m_documents.append( doc );
    }
}
