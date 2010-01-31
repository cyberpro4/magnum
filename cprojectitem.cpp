#include "cprojectitem.h"

CProjectItem::CProjectItem( CPROJECTITEM_PARAMS ){
    m_label = label;
    m_document = document;
    m_blockPointer = block;
    m_parent = parent;
    m_blockNumber = 0;

    qDebug() << "new item: " << m_label;
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

    QRegExp* procUnDef[4];
    procUnDef[0]=new QRegExp("[eE][nN][dD][ ]+");
    procUnDef[1]=new QRegExp("[eE]{1,1}[nN]{1,1}[dD]{1,1}[fF]{1,1}[cC]{1,1}[tT]{1,1}[ ]+");

    QRegExp* procDef[4];
    procDef[0] = new QRegExp( "([dD]{1,1}[eE]{1,1}[fF]{1,1}[ ]+[0-9a-zA-Z_]+[ ]*[\\(]{1}[0-9a-zA-Z_:, ]*[\\)]{1})" );
    procDef[1] = new QRegExp( "([dD]{1,1}[eE]{1,1}[fF]{1,1}[fF]{1,1}[cC]{1,1}[tT]{1,1}[ ]+[0-9a-zA-Z_\\[\\]]+[ ]+[0-9a-zA-Z_]+[ ]*[\\(]{1}[0-9a-zA-Z_,: ]*[\\)]{1})" );
    procDef[1] = new QRegExp( "(^[Ss]{1,1}[Tt]{1,1}[rR]{1,1}[uU]{1,1}[cC]{1,1}[ ]+[0-9a-zA-Z_\\[\\], ]+)" );

    while( block != (QTextBlock*)&block->end() ){
        /*
        ELIMINARE I COMMENTI NEL BLOCCO
        COME VERIFICARE LA DEFINIZIONE DELLE VARIABILI SENZA CONOSCERE I TIPI??? SAREBBE NECESSARIO EFFETTUARE PIU SCANSIONI DEL FILE
        */
        /*if( block->text() ){
          se il blocco è un simbolo di start di un nuovo item crea un nuovo item
          se il blocco è un simbolo di end termina la scansione
        }*/

        if( block->text().contains(*procDef[0])){
            m_childList.append( new CProjectItem( block->text(), m_document, &block->next(), m_parent ) );
        }

        if( block->text().contains(*procUnDef[0]) ){
            break;
        }

        m_blockNumber++;
        block = &block->next();
    }
    qDebug() << "end item: " << m_label;
}


