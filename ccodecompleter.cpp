#include "ccodecompleter.h"

CCodeCompleter::CCodeCompleter()
{
}


void CCodeCompleter::complete(CCodeEditor *editor , CProjectFile* project){

    if( project == NULL ) return;

    QList<CProjectItem*>*   items = project->childList();
    CProjectItem* item;

    for( int i = 0; i < items->count();i++ ){
        m_wordList.addItem( items->at( i )->label() );
    }

    CWordCompleter::complete( editor );

    //m_wordList.setCurrentItem( 0 );
}
