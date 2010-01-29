#include "cdocument.h"

CDocument::CDocument(const QString& file){
    m_editor = new CCodeEditor();
    m_editor->setDocumentOwner( this );

    if( !file.isNull() && file.length() > 0 )
	loadFromFile(file);
}

CDocument::~CDocument(){
    delete m_editor;
}

CCodeEditor* CDocument::editor(){
    return m_editor;
}

const QFileInfo& CDocument::fileInfo(){
    return m_fileInfo;
}

bool CDocument::saveToFile(const QString &file){

    QString savename( m_fileInfo.absoluteFilePath() );

    if( file.length() > 0 )
	savename = file;

    QFile fileq( savename );

    if( !fileq.open( QIODevice::WriteOnly ) )
	return false;

    fileq.write( m_editor->toPlainText().toLocal8Bit() );
#warning CONTROLLARE LA QUANTITA DI DATI SCRITTI

    fileq.close();

    return true;
}

bool CDocument::loadFromFile(const QString & filename ){
    QFile file(filename);

    if( !file.open( QIODevice::ReadOnly ) ){
	QMessageBox::warning( 0 , "Error" , "Unable to open file!" );
	return false;
    }

    m_editor->setPlainText( file.readAll() );

    file.close();

    m_fileInfo.setFile( filename );

    return true;
}
