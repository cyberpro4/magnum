#include "cdocument.h"

CDocument::CDocument(const QString& file){
    m_editor = new CCodeEditor();

    if( !file.isNull() && file.length() > 0 )
	loadFromFile(file);
}

CDocument::~CDocument(){
    delete m_editor;
}

CCodeEditor* CDocument::editor(){
    return m_editor;
}

bool CDocument::loadFromFile(const QString & filename ){
    QFile file(filename);

    if( !file.open( QIODevice::ReadOnly ) ){
	QMessageBox::warning( 0 , "Error" , "Unable to open file!" );
	return false;
    }

    m_editor->setPlainText( file.readAll() );

    file.close();

    return true;
}
