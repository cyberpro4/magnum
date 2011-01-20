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

#include "cproject.h"

CProject::CProject( QWidget* parent ):QDockWidget( "Project", parent ){

    setObjectName( "CProject" );

    this->setAllowedAreas( Qt::AllDockWidgetAreas );

    QWidget* mainContainer = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainContainer->setLayout( mainLayout );

    this->setWidget( mainContainer );

    QToolBar*   tool = new QToolBar( "Actions" );
    tool->setFloatable( false );
    tool->setIconSize( QSize( 16 , 16 ) );
    connect( tool->addAction( QIcon( ":refresh" ) , "Refresh" ) , SIGNAL(triggered()) ,
             this , SLOT(toolbarRefresh() ) );

    mainLayout->addWidget( tool );
    mainLayout->addWidget( &m_treeView );

    m_typeBag = new CProjectTypeBag();

    connect( &m_treeView, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this, SLOT(treeViewItemClicked(QTreeWidgetItem*,int)));
}

void CProject::documentPush( CDocument* document ){
    m_documentMap.insert( document,
                          new CProjectFile(
                                    document->fileInfo().absoluteFilePath(),
                                    document,
                                    &document->editor()->document()->firstBlock(),
                                    NULL )
                        );
    refreshTreeView();
}

void CProject::documentPurge( CDocument* document ){
    CProjectFile* projectFile = m_documentMap.value( document, NULL );
    if( projectFile != NULL ){
        delete projectFile;
        m_documentMap.remove( document );
    }
    refreshTreeView();
}

void CProject::documentChanged(  CDocument* document ){
#warning SVILUPPARE SCAN FILE CProject::documentChanged()
    CProjectFile* projectFile = m_documentMap.value( document, NULL );
    if( projectFile != NULL ){
        delete projectFile;
        m_documentMap.remove( document );
    }
    documentPush( document );
}

void CProject::refreshTreeView(){
    m_treeView.clear();

    const QList<CProjectFile*> fileList = m_documentMap.values();
    CProjectItem* item;
    foreach( item, fileList ){
        CProjectTreeViewItem* newTreeItem = new CProjectTreeViewItem( item, &m_treeView );
        addRecursiveChild( newTreeItem, NULL, item );
    }
}

void CProject::addRecursiveChild( CProjectTreeViewItem* treeParentItem, CProjectTreeViewItem* treeSubItem, CProjectItem* projectItem ){
    if( treeSubItem != NULL )   //NULL se Ã¨ un nodo principale
        treeParentItem->addChild( treeSubItem );

    QList<CProjectItem*>* itemList = projectItem->childList();
    CProjectItem* subItem;

    foreach( subItem, *itemList ){
        CProjectTreeViewItem* newTreeItem = new CProjectTreeViewItem( subItem );
        addRecursiveChild(
                (treeSubItem!=NULL)?treeSubItem:treeParentItem,
                newTreeItem,
                subItem );
    }
}

void CProject::toolbarRefresh(){
    QMutableMapIterator<CDocument*,CProjectFile*> di( m_documentMap );

    while( di.hasNext() ){
        di.next();

        if( di.value() != 0 ){
            delete di.value();
        }

        di.setValue( new CProjectFile(
                        di.key()->fileInfo().absoluteFilePath(),
                        di.key(),
                        &di.key()->editor()->document()->firstBlock(),
                        NULL ) );
    }

    refreshTreeView();
}

void CProject::treeViewItemClicked( QTreeWidgetItem * item, int column ){
    qDebug() << "goto document line: " << ((CProjectTreeViewItem*)item)->projectItem()->firstLineIndex();
    emit gotoDocumentLine(((CProjectTreeViewItem*)item)->projectItem()->document(),
                          ((CProjectTreeViewItem*)item)->projectItem()->firstLineIndex());
}
