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
