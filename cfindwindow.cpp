#include "cfindwindow.h"

CFindWindow::CFindWindow( QWidget* parent ) : QDockWidget( parent ){

    QVBoxLayout*    vbox = new QVBoxLayout();

    QHBoxLayout* whatlay = new QHBoxLayout();

    whatlay->addWidget( &m_whatLine );

    m_searchInProgressMovie.setFileName( ":find_load" );
    m_searchInProgressMovie.jumpToFrame(0);
    m_searchInProgress.setMovie( &m_searchInProgressMovie );
    whatlay->addWidget( &m_searchInProgress );

    vbox->addLayout( whatlay );
    vbox->addWidget( &m_resultsView );

    connect( &m_whatLine , SIGNAL(textChanged(const QString&)) , (QDockWidget*)this , SLOT(whatChanged(const QString& )));

    connect( &m_resultsView , SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)) , this , SLOT(resultItemDClicked(QTreeWidgetItem*,int)));
    connect( this , SIGNAL(clearList()) , &m_resultsView , SLOT(clear()) );

    QWidget* temp = new QWidget( );
    temp->setLayout(vbox);
    setWidget(temp);

    setWindowTitle( "Search" );
    setAllowedAreas( Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea );

    m_target = 0;

    m_searchThread = new CFindWindow_Thread( this );
}

CFindWindow::~CFindWindow(){
    m_searchThread->waitForSearchStop();
    delete m_searchThread;
}

void CFindWindow::loadMovie(bool on){
    if( on )
        m_searchInProgressMovie.start();
    else
        m_searchInProgressMovie.stop();
}

void CFindWindow::resultItemDClicked(QTreeWidgetItem *item ,int c ){
    CFindWindow_TreeItem* ite = dynamic_cast<CFindWindow_TreeItem*>(item);
    if( ite != 0 ){
        emit goTo(ite->m_document,ite->m_lineNumber);
    }
}

CDocument* CFindWindow::targetDocument(){
    return m_target;
}

void CFindWindow::setTargetDocument( CDocument* t ){
    m_searchThread->waitForSearchStop();
    emit clearList();
    m_resultsView.update();

    m_target = t;
}

void CFindWindow::whatChanged(const QString & text){
    m_searchThread->waitForSearchStop();
    m_searchThread->nth_run();
}

CFindWindow_Thread::CFindWindow_Thread(CFindWindow *wnd) : QThread( 0 ){
    m_findWindow = wnd;
    m_forceStopSearch = false;
    connect( this , SIGNAL(loadMovie(bool)) , wnd , SLOT(loadMovie(bool)) , Qt::QueuedConnection );
}

void CFindWindow_Thread::waitForSearchStop(){
    if( isRunning() ){
        m_forceStopSearch = true;
        wait();
    }

    m_forceStopSearch = false;
}

void CFindWindow_Thread::run(){
    nth_run();
}

void CFindWindow_Thread::nth_run(){

    CDocument* target = m_findWindow->m_target;
    QRegExp	regexp( m_findWindow->m_whatLine.text() );

    m_findWindow->m_resultsView.clear();

    if( target == 0 || !regexp.isValid() || m_findWindow->m_whatLine.text().length() < 1 ){
        return;
    }

    emit loadMovie(true);


    QTextBlock block = target->editor()->document()->firstBlock();
    QString textToInsert;

    regexp.setCaseSensitivity( Qt::CaseInsensitive );

    CFindWindow_TreeItem* main_ite = new CFindWindow_TreeItem( 0 );
    main_ite->setText( 0 , target->editor()->documentOwner()->fileInfo().fileName() );
    m_findWindow->m_resultsView.insertTopLevelItem( 0 , main_ite );

    while( block.isValid() && !m_forceStopSearch ){

        if( block.text().indexOf( regexp ) != -1 ){

            textToInsert = "";

            CFindWindow_TreeItem* ite = new CFindWindow_TreeItem();

            textToInsert += QString::number(block.blockNumber() + 1) + QString(", ");
            textToInsert += block.text();

            ite->setText( 0 , textToInsert );
            ite->m_document = target;
            ite->m_lineNumber = block.blockNumber();

            main_ite->addChild( ite );

        }

        block = block.next();
    }

     emit loadMovie(false);

    m_findWindow->m_resultsView.update();
}

CFindWindow_TreeItem::CFindWindow_TreeItem(QTreeWidgetItem *parent, int type) : QTreeWidgetItem( parent , type ){
}

CFindWindow_TreeItem::~CFindWindow_TreeItem(){

}
