#include "cproject.h"

CProject::CProject(){

}

void CProject::documentPush( CDocument* document ){
    m_documentList.append( document );
}

void CProject::documentChanged(){
#warning SVILUPPARE SCAN FILE CProject::documentChanged()
}
