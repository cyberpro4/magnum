#ifndef COPTIONS_H
#define COPTIONS_H

#include <QtGui>

class COptions_LeftBar : public QAbstractScrollArea {

private:

    QMap<QLabel*,QVariant>   m_items;
    QWidget                  m_mainWidget;
    QVBoxLayout              m_mainWidgetLay;

    int                      m_itemDimension;

public:

    COptions_LeftBar();

    void    addItem(const QPixmap& , const QVariant& );

    int     itemDimension(){return m_itemDimension;}
    void    setItemDimension(int dim);
};

class COptions : public QDialog {
private:

    COptions_LeftBar        m_leftArea;

public:
    COptions();
};

#endif // COPTIONS_H
