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

#include "cprojecttreeviewitem.h"

CProjectTreeViewItem::CProjectTreeViewItem( CProjectItem* projectItem, QTreeWidget* parent ):QTreeWidgetItem(parent){
    m_projectItem = projectItem;
    this->setText( 0, m_projectItem->label() );

    switch( projectItem->itemType() ){
    case CPROJECTITEM_TYPE_FILE:
        this->setIcon( 0, QIcon( CPROJECTTREEVIEWITEM_ICON_PATH + CPROJECTTREEVIEWITEM_ICON_FILE_NAME ));
        break;
    case CPROJECTITEM_TYPE_PROC:
        this->setIcon( 0, QIcon( CPROJECTTREEVIEWITEM_ICON_PATH + CPROJECTTREEVIEWITEM_ICON_PROC_NAME ));
        break;
    case CPROJECTITEM_TYPE_FUNC:
        this->setIcon( 0, QIcon( CPROJECTTREEVIEWITEM_ICON_PATH + CPROJECTTREEVIEWITEM_ICON_FUNC_NAME ));
        break;
    case CPROJECTITEM_TYPE_VAR:
        this->setIcon( 0, QIcon( CPROJECTTREEVIEWITEM_ICON_PATH + CPROJECTTREEVIEWITEM_ICON_VAR_NAME ));
        break;
    case CPROJECTITEM_TYPE_TYPE:
        this->setIcon( 0, QIcon( CPROJECTTREEVIEWITEM_ICON_PATH + CPROJECTTREEVIEWITEM_ICON_TYPE_NAME ));
        break;
    case CPROJECTITEM_TYPE_WSEC:
        this->setIcon( 0, QIcon( CPROJECTTREEVIEWITEM_ICON_PATH + CPROJECTTREEVIEWITEM_ICON_WSEC_NAME  ));
        break;
    case CPROJECTITEM_TYPE_WFOR:
        this->setIcon( 0, QIcon( CPROJECTTREEVIEWITEM_ICON_PATH + CPROJECTTREEVIEWITEM_ICON_WFOR_NAME ));
        break;
    case CPROJECTITEM_TYPE_INTE:
        this->setIcon( 0, QIcon( CPROJECTTREEVIEWITEM_ICON_PATH + CPROJECTTREEVIEWITEM_ICON_INTE_NAME ));
        break;
    }
}

CProjectItem* CProjectTreeViewItem::projectItem(){
    return m_projectItem;
}
