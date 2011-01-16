#include "cwordcompleter.h"

CWordCompleter::CWordCompleter(){
    setWindowFlags( windowFlags() | Qt::Popup );

    QVBoxLayout*    vbox = new QVBoxLayout();

    vbox->addWidget( &m_wordList );

    setLayout( vbox );

    m_currentEditor = 0;

    setFocusProxy( &m_wordList );

    m_wordList.installEventFilter( this );

}

bool CWordCompleter::eventFilter(QObject *obj, QEvent * eve){

    if( m_currentEditor == 0 ) return false;

    if( obj == m_currentEditor ){
        QPoint curPos( m_currentEditor->cursorRect().right() ,
                        m_currentEditor->cursorRect().top() );
        curPos += QPoint( 35 , 10 );
        move( curPos );

        updateWordList( pickStringToComplete() );
    }

    if( eve->type() == QEvent::KeyPress || eve->type() == QEvent::KeyRelease ){
        QKeyEvent *keyEve = static_cast<QKeyEvent *>(eve);

        if( keyEve->key() == Qt::Key_Escape ){
            hide();
            return true;
        }

        if( keyEve->key() == Qt::Key_Return && obj == m_currentEditor && isVisible() ){
            hide();
            return false;
        }

        if( keyEve->key() == Qt::Key_Return && obj == &m_wordList ){
            if( m_wordList.selectedItems().size() > 0 )
                completeString( m_wordList.selectedItems().at( 0 ) );

            hide();
            return true;
        }

        if( keyEve->key() == Qt::Key_Up || keyEve->key() == Qt::Key_Down ){
            return false;
        } else if( obj == &m_wordList ) {
            qApp->sendEvent( m_currentEditor , eve );
            return true;
        }

    }

    return false;
}

void CWordCompleter::hideEvent( QHideEvent* ){
    m_currentEditor->removeEventFilter( this );
    m_currentEditor->setFocus( Qt::OtherFocusReason );
    m_currentEditor = 0;

    setParent( 0 );
}

void CWordCompleter::completeString(QListWidgetItem *selectedItem){
    QString s = selectedItem->text();
    QString alS = pickStringToComplete();

    m_currentEditor->textCursor().insertText( s.remove( alS ) );
}

QString CWordCompleter::pickStringToComplete(){
    QString str = m_currentEditor->toPlainText();
    int pos = m_currentEditor->textCursor().anchor() - 1;

    QString tblock;

    if( pos < 0 ) return tblock;

    while( str.at( pos ) != ' ' && pos >= 0
           && str.at( pos ) != '\n' ){
        tblock = str.at( pos ) + tblock;
        pos--;
    }

    return tblock;
}

void CWordCompleter::updateWordList(QString currentString){
    int index;

    for(int i = 0;i < m_wordList.count();i++){
        index = m_wordList.item( i )->text().indexOf( currentString , 0 , Qt::CaseInsensitive );

        if( index == 0 )
            m_wordList.item(i)->setHidden( false );
        else
            m_wordList.item(i)->setHidden( true );
    }
}

void CWordCompleter::complete( CCodeEditor* editor ){

    setParent( editor );

    m_currentEditor = editor;

    m_currentEditor->installEventFilter( this );

    show();

    setFocus( Qt::OtherFocusReason );

    if( m_wordList.count() > 0 )
        m_wordList.setCurrentRow( 0 , QItemSelectionModel::SelectCurrent );
}
