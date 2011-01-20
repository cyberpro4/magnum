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

#include "coptions.h"

COptions_Label::COptions_Label(QWidget *obj) : QWidget( obj ){
    QVBoxLayout* lay = new QVBoxLayout();

    lay->addWidget( &m_pixmap );
    lay->addWidget( &m_description );

    setLayout( lay );
}

void COptions_Label::setLink(COptionPage *pg){
    m_link = pg;

    m_pixmap.setPixmap( pg->getLeftBarPixmap() );
    m_description.setText( pg->getLeftBarDescription() );
}

void COptions_Label::mouseReleaseEvent(QMouseEvent *ev){
    emit clicked( m_link );
}

COptions_LeftBar::COptions_LeftBar(){
    m_mainWidget.setLayout( &m_mainWidgetLay );
    setViewport( &m_mainWidget );

    m_itemDimension = 50;
}

void COptions_LeftBar::setItemDimension(int dim){
    m_itemDimension = dim;
}

void COptions_LeftBar::addItem( COptionPage* link ){
    COptions_Label* lbl = new COptions_Label( &m_mainWidget );

    lbl->setLink( link );

    m_items.append(lbl);

    if( m_mainWidgetLay.count() == 0 ){

        // In caso di primo inserimento aggiunto il widget
        m_mainWidgetLay.addWidget( lbl );
        // e lo stretch
        m_mainWidgetLay.addStretch();
    } else
        // Altrimenti dobbiamo inserire il widget
        // prima dello stretch
        m_mainWidgetLay.insertWidget( m_mainWidgetLay.count() - 1 , lbl );

}

COptions::COptions(){

    QVBoxLayout* vbox = new QVBoxLayout();

    QHBoxLayout* hbox = new QHBoxLayout();

    hbox->addWidget( &m_leftArea );
    hbox->addWidget( &m_optArea );

    vbox->addLayout( hbox );

    QPushButton*     apply = new QPushButton( "Apply" );
    connect( apply , SIGNAL(clicked()) , this , SLOT(applyClicked()) );
    vbox->addWidget( apply );

    setLayout( vbox );

    show();
}

void COptions::applyClicked(){

    QSettings   cfg( OPTIONS_FILENAME , QSettings::IniFormat );
    COptionPage* page;
    QMap<QString,QVariant> map;

    foreach( page , m_pages ){
        page->saveSettings( map );

        cfg.beginGroup( page->getUniqueKey() );

        QMapIterator<QString,QVariant> i(map);
        while (i.hasNext()) {
            i.next();
            cfg.setValue( i.key() , i.value() );
        }

        cfg.endGroup();
    }

    hide();
}

void COptions::addPage(COptionPage *page){
    if( page == 0 ) return;

    m_pages.append( page );

    m_leftArea.addItem( page );
}

void COptions::pageClicked(COptionPage *pg){
    if( pg == 0 )return;

    qDebug() << "asd";
    QSettings   cfg( OPTIONS_FILENAME , QSettings::IniFormat );
    cfg.beginGroup( pg->getUniqueKey() );

    QMap<QString,QVariant> map;
    QStringList list( cfg.allKeys() );
    QString slist;

    foreach( slist , list ){
        map[slist] = cfg.value( slist );
    }

    pg->loadSettings( map );
    m_optArea.setViewport( pg );
}
