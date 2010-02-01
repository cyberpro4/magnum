#include "cmagnumwin.h"

CMagnumWin::CMagnumWin(){

    setCentralWidget( &m_documentTabs );

    QMenu* file = m_mainMenu.addMenu( "File" );
    connect( file->addAction( "New" ) , SIGNAL(triggered()) , this , SLOT(newDocument()) );
    connect( file->addAction( "Open" ) , SIGNAL(triggered()) , this , SLOT(loadDocument()) );
    connect( file->addAction( "Save" ) , SIGNAL(triggered()) , this , SLOT(saveCurrentDocument()) );

    setMenuBar( &m_mainMenu );

    connect( m_mainToolbar.addAction("New") , SIGNAL(triggered()) , this , SLOT(newDocument()) );
    connect( m_mainToolbar.addAction("TEST") , SIGNAL(triggered()) , this , SLOT(testEvent()) );
    addToolBar( &m_mainToolbar );

    newDocument();
}


void CMagnumWin::testEvent(){
    ((CCodeEditor*)m_documentTabs.currentWidget())->foldBlocks( 2 , 5 );
}

void CMagnumWin::newDocument(){
    CDocument* doc = new CDocument();

    m_documents.append( doc );
    m_documentTabs.addTab( doc->editor() , doc->fileInfo().fileName() );

    doc->editor()->focusWidget();
}

void CMagnumWin::loadDocument(){

    QString filename = QFileDialog::getOpenFileName( this , "Load from file" , "" , "*.*" );

    if( !filename.isNull() ){
	CDocument* doc = new CDocument( filename );

	m_documentTabs.addTab( doc->editor() , doc->fileInfo().fileName() );
	m_documents.append( doc );
    }
}

void CMagnumWin::saveCurrentDocument(){

    CCodeEditor* ed = ((CCodeEditor*)m_documentTabs.currentWidget());

    if( ed != NULL){
	if( ed->documentOwner() != NULL ){

	    ed->documentOwner()->saveToFile();
	}
    }

}

void CMagnumWin::closeEvent(QCloseEvent *eve){

    CDocument* doc;
    foreach( doc , m_documents ){
	if( doc->editor()->document()->isModified() ){

	    if( QMessageBox::question( this , doc->fileInfo().fileName() , doc->fileInfo().fileName() + " has been modified: Save it?" , QMessageBox::Yes , QMessageBox::No ) == QMessageBox::Yes ){
		doc->saveToFile();
	    }
	}
    }

}
