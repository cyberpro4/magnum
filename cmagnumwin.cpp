#include "cmagnumwin.h"

CMagnumWin::CMagnumWin(){

    setCentralWidget( &m_documentTabs );

    QMenu* file = m_mainMenu.addMenu( "File" );
    connect( file->addAction( "New" ) , SIGNAL(triggered( bool )) , this , SLOT(newDocument(bool)) );
    connect( file->addAction( "Open" ) , SIGNAL(triggered( bool )) , this , SLOT(loadDocument(bool)) );
    connect( file->addAction( "Save" ) , SIGNAL(triggered( bool )) , this , SLOT(saveCurrentDocument(bool)) );

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

        m_documentTabs.addTab( doc->editor() , doc->fileInfo().fileName() );
        m_documents.append( doc );
    }
}

void CMagnumWin::saveCurrentDocument(bool ){

    CCodeEditor* ed = ((CCodeEditor*)m_documentTabs.currentWidget());

    if( ed != NULL){
        if( ed->documentOwner() != NULL ){

            ed->documentOwner()->saveToFile();
        }
    }

}

void CMagnumWin::closeEvent(QCloseEvent *eve){
    bool    someDocumentModified = false;

    CDocument* doc;
    foreach( doc , m_documents ){
        if( doc->editor()->document()->isModified() ){
            someDocumentModified = true;
            break;
        }
    }

    if( someDocumentModified ){
        QMessageBox::warning( 0 , "Sure" , "Some document modified ");
    }
}
