#ifndef CPROJECTITEM_H
#define CPROJECTITEM_H

#include <QtGui>
#include "cdocument.h"
#include "cmagnum_textblock.h"

#define CPROJECTITEM_REMOVE_STR_COMMENT(s)  if( s.contains(';') )s = s.mid( 0, s.indexOf(';') );

#define CPROJECTITEM_PARAMS CDocument* document, QTextBlock * block, CProjectItem* parent
#define CPROJECTITEM_VARS document,block,parent

#define CPROJECTITEM_TYPE_FILE          0
#define CPROJECTITEM_TYPE_PROC          1
#define CPROJECTITEM_TYPE_FUNC          2
#define CPROJECTITEM_TYPE_VAR           3
#define CPROJECTITEM_TYPE_TYPE          4   //TYPE STRUC
#define CPROJECTITEM_TYPE_WSEC          5   //WAIT SEC
#define CPROJECTITEM_TYPE_WFOR          6   //WAIT FOR
#define CPROJECTITEM_TYPE_INTE          7   //INTERRUPT


#define CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB     QString("[ \\t]+")
#define CPROJECTITEM_REGEXPR_DIGITS                 QString("[ |^|\t]{1}[0-9]+(\.([0-9])+){0,1}[ |$|\t]{1}")

class CProjectItem{

public:
    CProjectItem( CPROJECTITEM_PARAMS );
    virtual ~CProjectItem( );

    //ritorna il texblock del prossimo item
    QTextBlock* scan( QTextBlock* b );//scanna il documento a partire dalla linea identificata dal blocco identificato dal relativo parametro

    //verifica se il blocco passato come parametro è coerente con il blocco d'interesse
    static bool isIt( QTextBlock* block );

    CProjectItem*           parent(){           return m_parent;}
    QList<CProjectItem*>*   childList(){        return &m_childList;}
    QString                 label(){            return m_label;}
    CDocument*              document(){         return m_document;}
    int                     blockNumber(){      return m_blockNumber;}
    QTextBlock              fistTextBlock(){    return m_blockList.first();}
    QTextBlock              lastTextBlock(){    return m_blockList.last();}
    int                     itemType(){         return m_type;}
    int                     firstLineIndex(){   return m_lineIndex;}

protected:
    CProjectItem*               m_parent;
    QList<CProjectItem*>        m_childList;

    QString                     m_label;
    CDocument*                  m_document;

    int                         m_blockNumber;//numero di blocchi che compongono questo item
    QTextBlock*                 m_blockPointer;//puntatore al blocco di testo iniziale di questo item
    QList<QTextBlock>           m_blockList;//lista dei blocchi appartenenti all'item

    int                         m_type;//tipo di blocco

    int                         m_lineIndex;
};

#endif // CPROJECTITEM_H
