#ifndef CWORDCOMPLETER_H
#define CWORDCOMPLETER_H

#include <QtGui>
#include "cprojectitem.h"
#include "ccodeeditor.h"

class CWordCompleter : public QWidget {

protected:

    QListWidget     m_wordList;
    CCodeEditor*    m_currentEditor;

    void    updateWordList( QString currentString );

    virtual QString     pickStringToComplete();
    virtual void        completeString( QListWidgetItem* );

public:

    CWordCompleter();

    void complete( CCodeEditor* );

    bool eventFilter(QObject *, QEvent *);

    void hideEvent( QHideEvent* );

};

#endif // CWORDCOMPLETER_H
