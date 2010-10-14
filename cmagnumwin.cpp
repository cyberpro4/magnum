#include "cmagnumwin.h"
#include "coptions.h"

CMagnumWin::CMagnumWin() : m_shortcutFind( this ){

    m_documentTabs.setTabsClosable( true );
    connect( &m_documentTabs , SIGNAL(tabCloseRequested(int)) , this , SLOT(tabClose(int)) );
    connect( &m_documentTabs , SIGNAL(currentChanged(int)) , this , SLOT(currentDocumentChanged(int)) );
    setCentralWidget( &m_documentTabs );

    QMenu* file = m_mainMenu.addMenu( "File" );
    connect( file->addAction( "New" ) , SIGNAL(triggered()) , this , SLOT(newDocument()) );
    connect( file->addAction( "Open" ) , SIGNAL(triggered()) , this , SLOT(loadDocument()) );

    m_menuLastOpened.setTitle("Open recent");
    connect( &m_menuLastOpened , SIGNAL(triggered(QAction*)) , this , SLOT(lastOpened_Action(QAction*)) );
    file->addMenu( &m_menuLastOpened );
    file->addSeparator();

    connect( file->addAction( "Save" ) , SIGNAL(triggered()) , this , SLOT(saveCurrentDocument()) );
    connect( file->addAction( "Save As..." ) , SIGNAL(triggered()) , this , SLOT(saveCurrentDocumentAs()) );
    connect( file->addAction( "Save All" ) , SIGNAL(triggered()) , this , SLOT(saveAllDocument()) );

    file->addSeparator();
    connect( file->addAction( "Close" ) , SIGNAL(triggered()) , this , SLOT(closeCurrentDocument()) );
    connect( file->addAction( "Close All" ) , SIGNAL(triggered()) , this , SLOT(closeAllDocument()) );

    setMenuBar( &m_mainMenu );

    m_mainToolbar.setObjectName( "mainWindowToolBar" );

    connect( m_mainToolbar.addAction( QIcon(":doc_new") , "New" ) , SIGNAL(triggered()) , this , SLOT(newDocument()) );
    connect( m_mainToolbar.addAction( QIcon(":doc_open") , "Open" ) , SIGNAL(triggered()) , this , SLOT(loadDocument()) );
    connect( m_mainToolbar.addAction( QIcon(":doc_filesave") , "Save" ) , SIGNAL(triggered()) , this , SLOT(saveCurrentDocument()) );
    connect( m_mainToolbar.addAction( QIcon(":doc_filesaveas") , "Save as..." ) , SIGNAL(triggered()) , this , SLOT(saveCurrentDocumentAs()) );
    connect( m_mainToolbar.addAction( QIcon(":doc_filesaveall") , "Save All" ) , SIGNAL(triggered()) , this , SLOT(saveAllDocument()) );

    connect( m_mainToolbar.addAction("TEST") , SIGNAL(triggered()) , this , SLOT(testEvent()) );
    addToolBar( &m_mainToolbar );

    m_findWidget = new CFindWindow( this );
    connect( m_findWidget , SIGNAL(goTo(CDocument*,int)),this,SLOT(findWin_goTo(CDocument*,int)));
    addDockWidget( Qt::LeftDockWidgetArea , m_findWidget );

    newDocument();

    m_projectManager = new CProject( this );
    connect( m_projectManager, SIGNAL(gotoDocumentLine(CDocument*,int)), this, SLOT(findWin_goTo(CDocument*,int)) );
    addDockWidget( Qt::LeftDockWidgetArea, m_projectManager );

    m_shortcutFind.setKey( Qt::CTRL + Qt::Key_F );
    connect( &m_shortcutFind , SIGNAL(activated()) , this , SLOT( shortcutFind() ) );

    loadSettings();

    connect( &m_fileSystemNotification , SIGNAL(fileChanged(QString)) ,
             this , SLOT(fsNotify(QString)) );
}

void CMagnumWin::loadSettings(){
    QSettings	sett( SETTINGS_INI_FILENAME , QSettings::IniFormat );

    sett.beginGroup("Window");

        setGeometry( sett.value( "position" , QRect( 0,0 ,640,480) ).toRect() );

        if( sett.value( "maximized" , true ).toBool() )	    showMaximized();

        restoreState( sett.value( "wstate" , QByteArray() ).toByteArray() );

    sett.endGroup();

    sett.beginGroup("LastOpenedFile");

        QString item;
        QStringList list;

        list.append( sett.value( "List" ).toStringList() );

        //Push all item from last to first
        for(int _inv = list.size() - 1;_inv >= 0;_inv--)
            lastOpenedFile_Push( list.at( _inv ) );

        m_lastOpenDirectory = sett.value( "lastOpenDirectory" ).toString();

    sett.endGroup();
}

void CMagnumWin::saveSettings(){
    QSettings	sett( SETTINGS_INI_FILENAME , QSettings::IniFormat );

    sett.beginGroup("Window");

        sett.setValue( "position" , geometry() );
        sett.setValue( "maximized" , isMaximized() );
        sett.setValue( "wstate" , saveState() );

    sett.endGroup();

    sett.beginGroup("LastOpenedFile");
            sett.setValue( "List" , QStringList( m_lastOpenedFile ) );
            sett.setValue( "lastOpenDirectory" , m_lastOpenDirectory );

    sett.endGroup();
}

void CMagnumWin::lastOpened_Action(QAction *act){
    loadDocument(act->text());
}

void CMagnumWin::lastOpenedFile_Push(const QString &file){

    if( file.length() < 1 )
        return;

    m_lastOpenedFile.removeOne( file );

    // controllo che non contenga piu di 5 elementi
    m_lastOpenedFile.push_front( file );
    if( m_lastOpenedFile.size() > 5 ) m_lastOpenedFile.removeLast();
    m_menuLastOpened.clear();


    QString str;
    foreach( str , m_lastOpenedFile ){
        m_menuLastOpened.addAction( str );
    }
}

void CMagnumWin::tabClose(int index){
    closeDocument( ((CCodeEditor*)m_documentTabs.widget( index ))->documentOwner() );
}

void CMagnumWin::currentDocumentChanged(int tabIndex){

    // < 0 nel caso non ci sono piu documenti
    if( tabIndex < 0 ){
        m_findWidget->setTargetDocument( 0 );
        return;
    }

    m_findWidget->setTargetDocument( ((CCodeEditor*)m_documentTabs.widget( tabIndex ))->documentOwner() );

    m_fileSystemNotification.addPath(
      ((CCodeEditor*)m_documentTabs.widget( tabIndex ))->documentOwner()->fileInfo().absoluteFilePath() );
}

void CMagnumWin::testEvent(){
    //((CCodeEditor*)m_documentTabs.currentWidget())->documentOwner()->blockDataAt(5)->setFoldable( 10 );
    m_wordCompleter.complete( ((CCodeEditor*)m_documentTabs.currentWidget()) );
}

void CMagnumWin::newDocument(){
    CDocument* doc = new CDocument();

    m_documents.append( doc );
    m_documentTabs.addTab( doc->editor() , doc->fileInfo().fileName() );

    doc->editor()->focusWidget();
}

void CMagnumWin::loadDocument(const QString& str ){

    QString filename;

    if( str.length() > 0 )
        filename = str;
    else {
        filename = QFileDialog::getOpenFileName( this , "Load from file" , m_lastOpenDirectory , "*.*" );
        m_lastOpenDirectory = QFileInfo( filename ).absoluteDir().absolutePath();
    }

    if( !filename.isNull() ){

        CDocument* doc = new CDocument( filename );

        m_projectManager->documentPush( doc );

        lastOpenedFile_Push( filename );

        m_documentTabs.setCurrentIndex( m_documentTabs.addTab( doc->editor() , doc->fileInfo().fileName() ) );
        m_documents.append( doc );

    }

    saveSettings();
}

void CMagnumWin::saveAllDocument(){
    CDocument* doc;

    foreach( doc , m_documents ){
        doc->saveToFile();
    }
}

void CMagnumWin::saveCurrentDocumentAs(){
    CCodeEditor* ed = ((CCodeEditor*)m_documentTabs.currentWidget());

    if( ed != NULL){
        if( ed->documentOwner() != NULL ){

            QString path;
            path = QFileDialog::getSaveFileName( this , "Save as..." );


            if( path.isNull() || path.isEmpty() )
                return;

            ed->documentOwner()->saveToFile( path );
        }
    }
}

void CMagnumWin::saveCurrentDocument(){

    CCodeEditor* ed = ((CCodeEditor*)m_documentTabs.currentWidget());

    if( ed != NULL){
        if( ed->documentOwner() != NULL ){

            ed->documentOwner()->saveToFile( );
        }
    }

}


void CMagnumWin::closeDocument( CDocument* target ){

    if( target->editor()->document()->isModified() ){
        if( QMessageBox::question( this , target->fileInfo().fileName() , target->fileInfo().fileName() + " has been modified: Save it?" , QMessageBox::Yes , QMessageBox::No ) == QMessageBox::Yes ){
            target->saveToFile();
        }
    }

    m_fileSystemNotification.removePath( target->fileInfo().absoluteFilePath() );

    m_documentTabs.removeTab( m_documentTabs.indexOf( target->editor() ) );
    m_documents.removeOne( target );

    delete target;
}

void CMagnumWin::closeCurrentDocument(){

    if((CCodeEditor*)m_documentTabs.currentWidget() != 0 )
        closeDocument( ((CCodeEditor*)m_documentTabs.currentWidget())->documentOwner() );
}

void CMagnumWin::closeAllDocument(){
    CDocument* doc;
    foreach( doc , m_documents ){

        closeDocument( doc );

    }
}

void CMagnumWin::closeEvent(QCloseEvent *eve){

    saveSettings();

    closeAllDocument();
}

void CMagnumWin::findWin_goTo(CDocument *target, int nline){
    m_documentTabs.setCurrentWidget( target->editor() );

    QTextCursor cur = target->editor()->textCursor();

    cur.movePosition( QTextCursor::Start ,QTextCursor::KeepAnchor);
    cur.movePosition( QTextCursor::NextBlock , QTextCursor::MoveAnchor , nline  );
    //cur.setPosition( 0 , QTextCursor::MoveAnchor );

    target->editor()->setTextCursor( cur );
}

void CMagnumWin::shortcutFind(){
    CCodeEditor* ed = ((CCodeEditor*)m_documentTabs.currentWidget());
    m_findWidget->focusFind( ed->textCursor().selectedText() );
}

CMagnumWin::~CMagnumWin(){

}

void CMagnumWin::fsNotify( QString fileName ){
    int resp = QMessageBox::question( this , "File changed" ,
          fileName + "\n has been modified from an external editor.\nDo you want reload it?" ,
          QMessageBox::Yes | QMessageBox::No , QMessageBox::Yes );
    if( resp == QMessageBox::Yes ){

        CCodeEditor* ed = ((CCodeEditor*)m_documentTabs.currentWidget());
        ed->documentOwner()->loadFromFile( ed->documentOwner()->fileInfo().absoluteFilePath() );
        //TODO CProjectManager need to be reloaded here

    }
}
