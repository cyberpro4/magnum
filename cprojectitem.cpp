#include "cprojectitem.h"

CProjectItem::CProjectItem( CPROJECTITEM_PARAMS ){
    m_label = label;
    m_document = document;
    m_blockPointer = block;
    m_parent = parent;
    m_blockNumber = 0;

    scan( m_document, m_blockPointer );
}

CProjectItem::~CProjectItem(){
    CProjectItem* item;
    foreach( item, m_childList ){
        delete item;
    }
}

#warning CProjectItem::scan DOVREBBE RITORNARE IL PUNTATORE AL BLOCCO SU CUI HA TROVATO IL SIMBOLO DI END O FORSE NO DATO CHE VIENE SOVRASCRITTO IL PUNTATORE????
void CProjectItem::scan( CDocument* document, QTextBlock* block ){
    while( block != (QTextBlock*)&block->end() ){
        qDebug() << "CProjectItem::scan - new block: " << block->text();
        /*
        ELIMINARE I COMMENTI NEL BLOCCO
        COME VERIFICARE LA DEFINIZIONE DELLE VARIABILI SENZA CONOSCERE I TIPI??? SAREBBE NECESSARIO EFFETTUARE PIU SCANSIONI DEL FILE
        */
        /*if( block->text() ){
          se il blocco è un simbolo di start di un nuovo item crea un nuovo item
          se il blocco è un simbolo di end termina la scansione
        }*/
        m_blockNumber++;
        block = &block->next();
    }
    //QTextBlock::iterator iter = block->begin();
}
