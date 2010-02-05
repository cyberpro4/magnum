#include "cmagnumwin.h"

CMagnumWin::CMagnumWin(){

    m_documentTabs.setTabsClosable( true );
    connect( &m_documentTabs , SIGNAL(tabCloseRequested(int)) , this , SLOT(tabClose(int)) );
    connect( &m_documentTabs , SIGNAL(currentChanged(int)) , this , SLOT(currentDocumentChanged(int)) );
    setCentralWidget( &m_documentTabs );

    QMenu* file = m_mainMenu.addMenu( "File" );
    connect( file->addAction( "New" ) , SIGNAL(triggered()) , this , SLOT(newDocument()) );
    connect( file->addAction( "Open" ) , SIGNAL(triggered()) , this , SLOT(loadDocument()) );
    connect( file->addAction( "Save" ) , SIGNAL(triggered()) , this , SLOT(saveCurrentDocument()) );
    connect( file->addAction( "Close" ) , SIGNAL(triggered()) , this , SLOT(closeCurrentDocument()) );
    connect( file->addAction( "Close All" ) , SIGNAL(triggered()) , this , SLOT(closeAllDocument()) );

    setMenuBar( &m_mainMenu );

    connect( m_mainToolbar.addAction("New") , SIGNAL(triggered()) , this , SLOT(newDocument()) );
    connect( m_mainToolbar.addAction("TEST") , SIGNAL(triggered()) , this , SLOT(testEvent()) );
    addToolBar( &m_mainToolbar );

    newDocument();

    m_findWidget = new CFindWindow( this );
    addDockWidget( Qt::LeftDockWidgetArea , m_findWidget );
}

void CMagnumWin::tabClose(int index){
    closeDocument( ((CCodeEditor*)m_documentTabs.widget( index ))->documentOwner() );
}

void CMagnumWin::currentDocumentChanged(int tabIndex){

    // < 0 nel caso non ci sono piu documenti
    if( tabIndex < 0 )
        return;

    m_findWidget->setTargetDocument( ((CCodeEditor*)m_documentTabs.widget( tabIndex ))->documentOwner() );

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

void CMagnumWin::closeDocument( CDocument* target ){

    if( target->editor()->document()->isModified() ){
        if( QMessageBox::question( this , target->fileInfo().fileName() , target->fileInfo().fileName() + " has been modified: Save it?" , QMessageBox::Yes , QMessageBox::No ) == QMessageBox::Yes ){
            target->saveToFile();
        }
    }

    m_documentTabs.removeTab( m_documentTabs.indexOf( target->editor() ) );
    m_documents.removeOne( target );

    delete target;
}

void CMagnumWin::closeCurrentDocument(){
    closeDocument( ((CCodeEditor*)m_documentTabs.currentWidget())->documentOwner() );
}

void CMagnumWin::closeAllDocument(){
    CDocument* doc;
    foreach( doc , m_documents ){

        closeDocument( doc );

    }
}

void CMagnumWin::closeEvent(QCloseEvent *eve){

    closeAllDocument();

}

CMagnumWin::~CMagnumWin(){

    delete m_findWidget;
}
