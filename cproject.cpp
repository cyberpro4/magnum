#include "cproject.h"

CProject::CProject(){
    m_typeBag = new CProjectTypeBag();
}

void CProject::documentPush( CDocument* document ){
    m_documentList.append( document );
    qDebug()<< "______start building project albero ";
    m_childList.append(
            new CProjectFile(
                    document->fileInfo().absoluteFilePath(),
                    document,
                    &document->editor()->document()->firstBlock(),
                    NULL
                    )
            );
    qDebug()<< "______end building project albero ";
}

void CProject::documentChanged(){
#warning SVILUPPARE SCAN FILE CProject::documentChanged()
}
