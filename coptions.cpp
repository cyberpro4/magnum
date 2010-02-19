#include "coptions.h"

COptions_LeftBar::COptions_LeftBar(){

    setMinimumSize( 200 , 200 );
}

void COptions_LeftBar::addItem(QPixmap *, const QVariant & ){

}

COptions::COptions(){

    QHBoxLayout* hbox = new QHBoxLayout();

    hbox->addWidget( &m_leftArea );

    setLayout( hbox );

    show();
}
