/**************************************************************************

    Copyright (C) 2011 Claudio Cannatà.

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Magnum.  If not, see <http://www.gnu.org/licenses/>.

**************************************************************************/

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

    void documentPush( CDocument* document );
    void documentPurge( CDocument* document );

    //scanna il cproject e inserisce gli elementi nella lista
    void refreshTreeView();
    void addRecursiveChild( CProjectTreeViewItem* treeParentItem, CProjectTreeViewItem* treeSubItem, CProjectItem* projectItem );

private:
    QMap<CDocument*,CProjectFile*>  m_documentMap;
    //QList<CDocument*>       m_documentList;
    //QList<CProjectFile*>    m_childList;
    QString                 m_name;
    QString                 m_location;

    CProjectTypeBag*        m_typeBag;

    //per la visualizzazione
    CProjectTreeView        m_treeView;

public slots:
    void documentChanged( CDocument* document );

    void treeViewItemClicked( QTreeWidgetItem * item, int column );
    void toolbarRefresh();

signals:
    void gotoDocumentLine( CDocument*, int );

};

#endif // CPROJECT_H
