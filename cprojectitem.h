#ifndef CPROJECTITEM_H
#define CPROJECTITEM_H

#include <QtGui>
#include "cdocument.h"

#define CPROJECTITEM_PARAMS QString label, CDocument* document, QTextBlock* block, CProjectItem* parent
#define CPROJECTITEM_VARS label,document,block,parent

class CProjectItem{

public:
    CProjectItem( CPROJECTITEM_PARAMS );
    ~CProjectItem( );

    void scan( CDocument* document, QTextBlock* block );//scanna il documento a partire dalla linea identificata dal blocco identificato dal relativo parametro

    CProjectItem*           parent(){       return m_parent;}
    QList<CProjectItem*>*   childList(){    return &m_childList;}
    QString                 label(){        return m_label;}
    CDocument*              document(){     return m_document;}
    int                     blockNumber(){  return m_blockNumber;}
    QTextBlock*             textBlock(){    return m_blockPointer;}

private:
    CProjectItem*               m_parent;
    QList<CProjectItem*>        m_childList;

    QString                     m_label;
    CDocument*                  m_document;

    int                         m_blockNumber;//numero di blocchi che compongono questo item
    QTextBlock*                 m_blockPointer;//puntatore al blocco di testo iniziale di questo item

};

#endif // CPROJECTITEM_H
