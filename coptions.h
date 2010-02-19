#ifndef COPTIONS_H
#define COPTIONS_H

#include <QtGui>

class COptions_LeftBar : public QAbstractScrollArea {

private:

    QMap<QLabel,QVariant>   m_items;

public:

    COptions_LeftBar();

    void    addItem( QPixmap* , const QVariant& );
};

class COptions : public QDialog {
private:

    COptions_LeftBar        m_leftArea;

public:
    COptions();
};

#endif // COPTIONS_H
