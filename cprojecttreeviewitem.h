#ifndef CPROJECTTREEVIEWITEM_H
#define CPROJECTTREEVIEWITEM_H

#include <QtGui>
#include "cprojectitem.h"

#define CPROJECTTREEVIEWITEM_ICON_PATH          QString("./res/icons/")
#define CPROJECTTREEVIEWITEM_ICON_FILE_NAME     "file.png"
#define CPROJECTTREEVIEWITEM_ICON_PROC_NAME     "proc.png"
#define CPROJECTTREEVIEWITEM_ICON_FUNC_NAME     "func.png"
#define CPROJECTTREEVIEWITEM_ICON_VAR_NAME      "var.png"
#define CPROJECTTREEVIEWITEM_ICON_TYPE_NAME     "type.png"
#define CPROJECTTREEVIEWITEM_ICON_WSEC_NAME     "wait.png"

class CProjectTreeViewItem:public QTreeWidgetItem{
public:
    CProjectTreeViewItem( CProjectItem* projectItem, QTreeWidget* parent = NULL );

    CProjectItem* projectItem();

private:
    CProjectItem*   m_projectItem;

};

#endif // CPROJECTTREEVIEWITEM_H
