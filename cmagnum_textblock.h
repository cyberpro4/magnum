#ifndef CMAGNUM_TEXTBLOCK_H
#define CMAGNUM_TEXTBLOCK_H

#include <QDebug>
#include <QTextBlock>
#include <QTextBlockUserData>

class CMagnum_TextBlock : public QTextBlockUserData {

private:

    int             m_foldable;
    int             m_parentFold;
    QTextBlock      m_blockPointer;

public:
    CMagnum_TextBlock( QTextBlock );
    ~CMagnum_TextBlock();

    void    setFoldable(int last_line);
    int     foldable();

    int     parentFold();

public:

    static CMagnum_TextBlock* getDataByBlock( QTextBlock* );

};

#endif // CMAGNUM_TEXTBLOCK_H
