#ifndef CPROJECTITEM_H
#define CPROJECTITEM_H

#include <QtGui>

#define CPROJECTITEM_PARAMS QString label, QString file, int blockNumber, QTextBlock* block
#define CPROJECTITEM_VARS label,file,blockNumber,block

class CProjectItem{

public:
    CProjectItem( CPROJECTITEM_PARAMS );

    QString     label(){        return m_label;}
    QString     sourceFile(){   return m_sourceFile;}
    QString     sourceLine(){   return m_sourceLine;}
    int         blockNumber(){  return m_blockNumber;}

    QTextBlock* textBlock(){    return m_blockPointer;}

private:
    QString         m_label;
    QString         m_sourceFile;
    QString         m_sourceLine;

    int             m_blockNumber;
    QTextBlock*     m_blockPointer;

};

#endif // CPROJECTITEM_H
