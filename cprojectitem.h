#ifndef CPROJECTITEM_H
#define CPROJECTITEM_H

#include <QtGui>
#include "cdocument.h"

#define CPROJECTITEM_PARAMS QString label, CDocument* document, int blockNumber, QTextBlock* block
#define CPROJECTITEM_VARS label,document,blockNumber,block

class CProjectItem{

public:
    CProjectItem( CPROJECTITEM_PARAMS );

    QString     label(){        return m_label;}
    CDocument*  document(){     return m_document;}
    QString     sourceLine(){   return m_sourceLine;}
    int         blockNumber(){  return m_blockNumber;}

    QTextBlock* textBlock(){    return m_blockPointer;}

private:
    QString         m_label;
    CDocument*      m_document;
    QString         m_sourceLine;

    int             m_blockNumber;
    QTextBlock*     m_blockPointer;

};

#endif // CPROJECTITEM_H
