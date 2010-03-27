#ifndef CPROJECT_H
#define CPROJECT_H

#include <QtCore>
#include "cdocument.h"
#include "cprojectfile.h"
#include "cprojecttypebag.h"

//per la visualizzazione
#include "cprojecttreeview.h"


class CProject:public QDockWidget{
    Q_OBJECT
public:
    CProject( QWidget* parent );

    void                            documentPush( CDocument* document );
    void                            documentPurge( CDocument* document );

    //scanna il cproject e inserisce gli elementi nella lista
    void                            refreshTreeView();
    void                            addRecursiveChild( CProjectTreeViewItem* treeParentItem, CProjectTreeViewItem* treeSubItem, CProjectItem* projectItem );

    QMap<CDocument*,CProjectFile*>* getProjectDocumentMap();


private:
    QMap<CDocument*,CProjectFile*>  m_documentMap;
    //QList<CDocument*>             m_documentList;
    //QList<CProjectFile*>          m_childList;
    QString                         m_name;
    QString                         m_location;

    CProjectTypeBag*                m_typeBag;

    //per la visualizzazione
    CProjectTreeView                m_treeView;

public slots:
    void                            documentChanged( CDocument* document );

    void                            treeViewItemClicked( QTreeWidgetItem * item, int column );

signals:
    void                            gotoDocumentLine( CDocument*, int );

};

#endif // CPROJECT_H
