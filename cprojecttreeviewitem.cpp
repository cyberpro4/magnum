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
    }
}

CProjectItem* CProjectTreeViewItem::projectItem(){
    return m_projectItem;
}
