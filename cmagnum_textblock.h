#ifndef CMAGNUM_TEXTBLOCK_H
#define CMAGNUM_TEXTBLOCK_H

#include <QTextBlockUserData>

class CMagnum_TextBlock : public QTextBlockUserData {

private:

    int     m_foldable;

public:
    CMagnum_TextBlock();
    ~CMagnum_TextBlock();

    void setFoldable(int last_line);
    int foldable();
};

#endif // CMAGNUM_TEXTBLOCK_H
