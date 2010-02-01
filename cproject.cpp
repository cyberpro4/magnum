#include "cproject.h"

CProject::CProject(){

}

void CProject::documentPush( CDocument* document ){
    m_documentList.append( document );
    m_childList.append(
            new CProjectFile(
                    document->fileInfo().absoluteFilePath(),
                    document,
                    &document->editor()->document()->firstBlock(),
                    NULL
                    )
            );

}

void CProject::documentChanged(){
#warning SVILUPPARE SCAN FILE CProject::documentChanged()
}
