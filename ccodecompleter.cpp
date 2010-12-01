#include "ccodecompleter.h"

CCodeCompleter::CCodeCompleter()
{
}

void CCodeCompleter::recursiveFillWordList( CProjectItem* project , int bn ){
    QList<CProjectItem*>*   items = project->childList();
    if( items == 0 ) return;

    qDebug() << "cc" << items->count();
    CProjectItem* item = NULL;

    for( int i = 0; i < items->count();i++ ){
        if( items->at( i ) == 0 ) continue;

        item = items->at( i );

        m_wordList.addItem( item->label() );

        qDebug() << "a";

        if( item->fistTextBlock() == 0 ||
            item->lastTextBlock() == 0 )
            continue;

        /*if( bn > item->fistTextBlock()->firstLineNumber() &&
            bn < item->lastTextBlock()->firstLineNumber() ){
            //recursiveFillWordList( item , bn );
        }*/

    }
}

void CCodeCompleter::complete(CCodeEditor *editor , CProjectFile* project){

    if( project == NULL ) return;

    int cursorBlock = editor->textCursor().block().firstLineNumber();
    qDebug() << "cb " << cursorBlock;
    recursiveFillWordList( (CProjectItem*)project , cursorBlock );

    CWordCompleter::complete( editor );

    //m_wordList.setCurrentItem( 0 );
}
