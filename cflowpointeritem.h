#ifndef CFLOWPOINTERITEM_H
#define CFLOWPOINTERITEM_H

#include <QtGui>
#include "cdocument.h"
#include "cproject.h"

//Rappresenta ogni elemento cliccabile sul flow pointer relativo ad ogni funzione nel programma
class CFlowPointerItem : public QGroupBox{
    Q_OBJECT
public:
    CFlowPointerItem( CProjectItem* m_projectItem, int callLine = 0  );

    CProjectItem* projectItem();

    void addChildItem( CFlowPointerItem* child );

    int firstLineNumber();
    int lastLineNumber();

    void updateVisibility();
    void forceVisibility();

    void setBasePalette( QPalette p );

    void setCheckability( bool checkable );

    void checkIfContainsLineNumber( int line, CDocument* doc );

protected:
    void mousePressEvent ( QMouseEvent * event );
    void mouseMoveEvent ( QMouseEvent * event );

private:
    CProjectItem*       m_projectItem;      //item di tipo funzione o procedura a cui si riferisce il flow pointer item
    QString             m_label;            //label, nome funzione
//  CDocument*          m_document;         //documento a cui ci si riferisce

    int                 m_startLine;        //linea di start a cui punta
    int                 m_endLine;          //linea di end a cui punta

    int                 m_callLine;         //numero di linea dove viene effettuata la chiamata della funzione

    bool                m_active;           //flag che indica se ci si trova nella relativa funzione

    QList<CFlowPointerItem*>    m_childList;//sotto items

    QPalette            m_basePalette;      //colore di base
    QPalette            m_activePalette;      //colore se ci si trova nella dichiarazione
    QPalette            m_callLinePalette;      //colore se ci si trova sulla chiamata

signals:
    void gotoDocumentLine( CDocument* document, int line );

};

#endif // CFLOWPOINTERITEM_H
