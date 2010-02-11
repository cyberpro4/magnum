#include "cdocument.h"

CDocument::CDocument(const QString& file){
    m_editor = new CCodeEditor();
    m_editor->setDocumentOwner( this );

    m_fileInfo.setFile( "Untitled.src" );

    if( !file.isNull() && file.length() > 0 )
        loadFromFile(file);

}

CDocument::~CDocument(){
    delete m_editor;
}

CMagnum_TextBlock* CDocument::blockDataAt(int linenumber){
    QTextBlock b = editor()->document()->findBlockByLineNumber(linenumber);

    QTextBlockUserData* udata = b.userData();

    if( udata != 0 ){
        CMagnum_TextBlock* mudata = dynamic_cast<CMagnum_TextBlock*>(udata);

        if( mudata != 0 )
            return mudata;

        qDebug() << "OHHHH O_O CHECK HERE!!!";

    } else {

        CMagnum_TextBlock* mudata = new CMagnum_TextBlock();
        b.setUserData( mudata );

        return mudata;
    }

    return 0;
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
    else if( !m_fileInfo.exists() ){
        savename = QFileDialog::getSaveFileName( 0 , "Save to.." );
    }

    QFile fileq( savename );

    if( !fileq.open( QIODevice::WriteOnly ) ){
        QMessageBox::critical( 0 , "Save failed!" , "Unable to open the file for save!" );
        return false;
    }

    QByteArray bit8 = m_editor->toPlainText().toLocal8Bit();
    qint64 savedBytes = fileq.write( bit8 );

    fileq.close();

    if( savedBytes != bit8.size() ){
        QMessageBox::critical( 0 , "Save failed!" , "Seem that not all bytes have been written." );
        return false;
    }

    editor()->document()->setModified( false );
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
