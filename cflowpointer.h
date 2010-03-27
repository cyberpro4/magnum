#ifndef CFLOWPOINTER_H
#define CFLOWPOINTER_H

#include <QtGui>
#include "cdocument.h"
#include "cproject.h"
#include "cflowpointeritem.h"

class CFlowPointer:public QDockWidget{
    Q_OBJECT
public:
    CFlowPointer( CProject* project, QWidget* parent );

    void        setCurrentDocument( CDocument* document );

    void        scanProjectFunctionsItems();

    void        recursiveScanFunctions( CProjectItem* item );

    QString     getProjectItemLabel( CProjectItem* item );

    CProjectItem* getRootFunction( CProjectFile* file );

    void        recursiveBuildFlowPointerTree( CFlowPointerItem* momItem );

private:
    QString     buildProjectItemRegExpr( CProjectItem* item );

    CProjectItem* getLineContainedProjectItem( QString lineText );

private:
    CProject*                   m_project;
    CDocument*                  m_currentDocument;

    QFrame*                     mainWidget;
    QScrollArea*                scrollArea;

    QList<CProjectItem*>        m_projectFunctionItems; //lista delle funzioni nel programma
    QMap<QString,CProjectItem*> m_projectFunctionItemsRegExpr; //lista delle espressioni regolari per itentificare le chiamate a funzione nel programma

    CFlowPointerItem*           m_rootItem; //nodo radice del flow pointer


public slots:
    void gotoDocumentLine(CDocument*,int);

    void updateVisibility();       //nasconde i fold non checked e imposta luminosi quelli in cui ci si trova con il puntatore
    void forceVisibility();         //reimposta visibility per tutti gli items del flow pointer

signals:
    void gotoDocumentLinePropagate(CDocument*,int);

};

#endif // CFLOWPOINTER_H
