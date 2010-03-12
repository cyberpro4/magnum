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
    connect( lbl , SIGNAL(clicked(COptionPage*)) , this , SLOT(label_clicked(COptionPage* )));

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

void COptions_LeftBar::label_clicked(COptionPage* page){
    emit itemClicked( page );
}

COptions*   COptions::stc_Instance = 0;

COptions*   COptions::getInstance(){
    return stc_Instance;
}

COptions::COptions(){

    stc_Instance = this;

    QVBoxLayout* vbox = new QVBoxLayout();

    QHBoxLayout* hbox = new QHBoxLayout();

    hbox->addWidget( &m_leftArea );
    hbox->addWidget( &m_optArea );

    vbox->addLayout( hbox );

    QPushButton*     apply = new QPushButton( "Apply" );
    connect( apply , SIGNAL(clicked()) , this , SLOT(applyClicked()) );
    vbox->addWidget( apply );

    setLayout( vbox );

    connect( &m_leftArea , SIGNAL( itemClicked(COptionPage*)) , this , SLOT(pageClicked(COptionPage*)) );
    show();
}

void COptions::applyClicked(){

    QSettings   cfg( OPTIONS_FILENAME , QSettings::IniFormat );
    COptionPage* page;

    foreach( page , m_pages ){
        page->saveSettings( m_lastValuesMap );

        cfg.beginGroup( page->getUniqueKey() );

        QMapIterator<QString,QVariant> i(m_lastValuesMap);
        while (i.hasNext()) {
            i.next();
            cfg.setValue( i.key() , i.value() );
        }

        cfg.endGroup();
    }

    emit optionsChanged();

    hide();
}

void COptions::showEvent(QShowEvent *eve){
    COptionPage* page;

    foreach( page , m_pages ){
        page->loadSettings( m_lastValuesMap );
    }
}

void COptions::addPage(COptionPage *page){
    if( page == 0 ) return;

    m_pages.append( page );
    m_leftArea.addItem( page );

    page->loadSettings( m_lastValuesMap );
    emit optionsChanged();
}

QVariant COptions::getValue(const QString &s){
    return m_lastValuesMap[s];
}

void COptions::pageClicked(COptionPage *pg){
    if( pg == 0 )return;

    qDebug() << "asd";
    QSettings   cfg( OPTIONS_FILENAME , QSettings::IniFormat );
    cfg.beginGroup( pg->getUniqueKey() );

    QStringList list( cfg.allKeys() );
    QString slist;

    foreach( slist , list ){
        m_lastValuesMap[slist] = cfg.value( slist );
    }

    pg->loadSettings( m_lastValuesMap );
    m_optArea.setViewport( pg );
}
