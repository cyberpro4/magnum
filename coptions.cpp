#include "coptions.h"

COptions_Label::COptions_Label(QWidget *obj) : QWidget( obj ){
    QVBoxLayout* lay = new QVBoxLayout();

    lay->addWidget( &m_pixmap );
    m_pixmap.setMinimumHeight( 70 );
    lay->addWidget( &m_description );

    setLayout( lay );
}

void COptions_Label::setLink(COptionPage *pg){
    m_link = pg;

    m_pixmap.setPixmap( pg->getLeftBarPixmap().scaledToHeight( 70 ) );
    m_description.setText( pg->getLeftBarDescription() );
}

void COptions_Label::mouseReleaseEvent(QMouseEvent *ev){
    emit clicked( m_link );
}

COptions_LeftBar::COptions_LeftBar(){
    m_mainWidget.setLayout( &m_mainWidgetLay );
    setViewport( &m_mainWidget );
}

void COptions_LeftBar::addItem( COptionPage* link ){
    COptions_Label* lbl = new COptions_Label( &m_mainWidget );

    lbl->setLink( link );
    connect( lbl , SIGNAL(clicked(COptionPage*)) , this , SLOT(label_clicked(COptionPage* )) , Qt::DirectConnection );

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

    hbox = new QHBoxLayout();
    hbox->addStretch();
    hbox->addWidget( apply );
    vbox->addLayout( hbox );

    setLayout( vbox );

    QWidget* wid = new QWidget();
    wid->setLayout( &m_viewportContainer );
    m_optArea.setViewport( wid );

    connect( &m_leftArea , SIGNAL( itemClicked(COptionPage*)) , this , SLOT(pageClicked(COptionPage*)) );
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

    if( m_pages.size() == 0 ) return;

    pageClicked( m_pages[0] );
}

void COptions::addPage(COptionPage *page){
    if( page == 0 ) return;

    m_pages.append( page );
    m_leftArea.addItem( page );
    m_viewportContainer.addWidget( page );

    pageClicked( page );
    emit optionsChanged();
}

QVariant COptions::getValue(const QString &s){
    return m_lastValuesMap[s];
}

void COptions::showPage(COptionPage *pg){
    COptionPage* val;

    foreach( val , m_pages ){
        if( val == pg )
            val->show();
        else
            val->hide();
    }
}

void COptions::pageClicked(COptionPage *pg){
    if( pg == 0 )return;

    QSettings   cfg( OPTIONS_FILENAME , QSettings::IniFormat );
    cfg.beginGroup( pg->getUniqueKey() );

    QStringList list( cfg.allKeys() );
    QString slist;

    foreach( slist , list ){
        m_lastValuesMap[slist] = cfg.value( slist );
    }

    pg->loadSettings( m_lastValuesMap );

    showPage( pg );
}
