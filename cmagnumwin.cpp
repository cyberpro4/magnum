#include "cmagnumwin.h"

CMagnumWin::CMagnumWin(){

    setCentralWidget( &m_documentTabs );

    QMenu* file = m_mainMenu.addMenu( "File" );
    connect( file->addAction( "New" ) , SIGNAL(triggered( bool )) , this , SLOT(newDocument(bool)) );
    connect( file->addAction( "Open" ) , SIGNAL(triggered( bool )) , this , SLOT(loadDocument(bool)) );

    setMenuBar( &m_mainMenu );
}

void CMagnumWin::newDocument(bool checked){
    CCodeEditor* codeed = new CCodeEditor();

    m_editors.append( codeed );
    m_documentTabs.addTab( codeed , "NEW" );
}

void CMagnumWin::loadDocument(bool checked ){

    QString filename = QFileDialog::getOpenFileName( this , "Load from file" , "" , "*.*" );

    if( !filename.isNull() ){


        QFile file(filename);
        if( !file.open( QIODevice::ReadOnly ) ){
            QMessageBox::warning( this , "Error" , "Unable to open file!" );
            return;
        }

        CCodeEditor* codeed = new CCodeEditor();

        codeed->setPlainText( file.readAll() );

        file.close();

        m_editors.append( codeed );

        m_documentTabs.addTab( codeed , filename );
    }
}
