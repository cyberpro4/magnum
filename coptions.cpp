#include "coptions.h"

COptions_LeftBar::COptions_LeftBar(){
    m_mainWidget.setLayout( &m_mainWidgetLay );
    setViewport( &m_mainWidget );

    m_itemDimension = 50;
}

void COptions_LeftBar::setItemDimension(int dim){
    m_itemDimension = dim;
}

void COptions_LeftBar::addItem(const QPixmap& pix , const QVariant & ret ){
    QLabel* lbl = new QLabel( &m_mainWidget );
    lbl->setPixmap( pix.scaled( 50 , 50 ) );

    m_items[lbl] = ret;

    if( m_mainWidgetLay.count() == 0 ){
        m_mainWidgetLay.addWidget( lbl );
        m_mainWidgetLay.addStretch();
    } else
        m_mainWidgetLay.insertWidget( m_mainWidgetLay.count() - 1 , lbl );

}

COptions::COptions(){

    QHBoxLayout* hbox = new QHBoxLayout();

    m_leftArea.addItem( QPixmap( "lol.png" ) , QVariant("lol") );
    m_leftArea.addItem( QPixmap( "lol.png" ) , QVariant("asd") );

    hbox->addWidget( &m_leftArea );
    setLayout( hbox );

    show();
}
