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

#ifndef CPROJECTTREEVIEWITEM_H
#define CPROJECTTREEVIEWITEM_H

#include <QtGui>
#include "cprojectitem.h"

#define CPROJECTTREEVIEWITEM_ICON_PATH          QString(":prj")
#define CPROJECTTREEVIEWITEM_ICON_FILE_NAME     "file"
#define CPROJECTTREEVIEWITEM_ICON_PROC_NAME     "proc"
#define CPROJECTTREEVIEWITEM_ICON_FUNC_NAME     "func"
#define CPROJECTTREEVIEWITEM_ICON_VAR_NAME      "var"
#define CPROJECTTREEVIEWITEM_ICON_TYPE_NAME     "type"
#define CPROJECTTREEVIEWITEM_ICON_WSEC_NAME     "wait"
#define CPROJECTTREEVIEWITEM_ICON_WFOR_NAME     "waitfor"
#define CPROJECTTREEVIEWITEM_ICON_INTE_NAME     "interrupt"

class CProjectTreeViewItem:public QTreeWidgetItem{
public:
    CProjectTreeViewItem( CProjectItem* projectItem, QTreeWidget* parent = NULL );

    CProjectItem* projectItem();

private:
    CProjectItem*   m_projectItem;

};

#endif // CPROJECTTREEVIEWITEM_H
