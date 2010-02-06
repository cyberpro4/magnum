#include "cfindwindow.h"

CFindWindow::CFindWindow( QWidget* parent ) : QDockWidget( parent ){

    QVBoxLayout*    vbox = new QVBoxLayout();

    vbox->addWidget( &m_whatLine );
    vbox->addWidget( &m_resultsView );
    connect( &m_whatLine , SIGNAL(textChanged(QString)) , (QDockWidget*)this , SLOT(whatChanged(QString)));
    connect( &m_resultsView , SIGNAL(itemDoubleClicked(QListWidgetItem*)) , this , SLOT(resultItemDClicked(QListWidgetItem*)));

    QWidget* temp = new QWidget( );
    temp->setLayout(vbox);
    setWidget(temp);

    setWindowTitle( "Search" );
    setAllowedAreas( Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea );

    m_target = 0;

    m_searchThread = new CFindWindow_Thread( this );
}

CFindWindow::~CFindWindow(){
    delete m_searchThread;
}

void CFindWindow::resultItemDClicked(QListWidgetItem *item ){
    qDebug() << item->text();
}

CDocument* CFindWindow::targetDocument(){
    return m_target;
}

void CFindWindow::setTargetDocument( CDocument* t ){
    m_searchThread->waitForSearchStop();
    m_target = t;
}

void CFindWindow::whatChanged(const QString & text){
    m_searchThread->waitForSearchStop();
    m_searchThread->start();
}

CFindWindow_Thread::CFindWindow_Thread(CFindWindow *wnd) : QThread( 0 ){
    m_findWindow = wnd;
    m_forceStopSearch = false;
}

void CFindWindow_Thread::waitForSearchStop(){
    if( isRunning() ){
	m_forceStopSearch = true;
	wait();
    }

    m_forceStopSearch = false;
}

void CFindWindow_Thread::run(){

    CDocument* target = m_findWindow->m_target;
    QString	regexp = m_findWindow->m_whatLine.text();

    if( target == 0 || regexp.length() < 1 )
	return;

    while( m_findWindow->m_resultsView.takeItem( 0 ) != 0 );

    QTextBlock block = target->editor()->document()->firstBlock();

    while( block.isValid() && !m_forceStopSearch ){

	if( block.text().indexOf( regexp ) != -1 ){
	    QListWidgetItem* ite = new QListWidgetItem( &m_findWindow->m_resultsView );

	    ite->setText( target->fileInfo().fileName() + QString( ",( ") + QString::number(block.firstLineNumber()) + QString(" )") );

	    m_findWindow->m_resultsView.insertItem( 0 , ite );

	}

	block = block.next();
    }

    m_findWindow->m_resultsView.update();
}
