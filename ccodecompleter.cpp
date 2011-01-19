#include "ccodecompleter.h"

CCodeCompleter::CCodeCompleter()
{
}

void CCodeCompleter::recursiveFillWordList( CProjectItem* project , int bn ){
    QList<CProjectItem*>*   items = project->childList();
    if( items == 0 ) return;

    CProjectItem* item = NULL;

    for( int i = 0; i < items->count();i++ ){
        if( items->at( i ) == 0 ) continue;

        item = items->at( i );

        QString ico;

        if( dynamic_cast<CProjectFunction*>(item) != 0 ) ico = ":prjfunc";
        if( dynamic_cast<CProjectProcedure*>(item) != 0 ) ico = ":prjproc";
        if( dynamic_cast<CProjectVariable*>(item) != 0 ) ico = ":prjvar";

        QListWidgetItem     *litem = new QListWidgetItem( QIcon( ico ) , item->label() );
        m_wordList.addItem( litem );

        if( !item->fistTextBlock().isValid() ||
            !item->lastTextBlock().isValid() )
            continue;

        qDebug() << item->fistTextBlock().text();

        if( bn > item->fistTextBlock().firstLineNumber() &&
            bn < item->lastTextBlock().firstLineNumber() ){
            recursiveFillWordList( item , bn );
        }

    }
}

void CCodeCompleter::complete(CCodeEditor *editor , CProjectFile* project){

    if( project == NULL ) return;

    int cursorBlock = editor->textCursor().block().firstLineNumber();

    m_wordList.clear();

    recursiveFillWordList( (CProjectItem*)project , cursorBlock );

    CWordCompleter::complete( editor );
}
