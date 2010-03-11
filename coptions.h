#ifndef COPTIONS_H
#define COPTIONS_H

#include <QtGui>
#include "coptionpage.h"

class COptions_Label : public QWidget {

    Q_OBJECT

private:

    COptionPage*    m_link;
    QLabel          m_description;
    QLabel          m_pixmap;

public:

    COptions_Label( QWidget* );

    void setLink(COptionPage* pg);
    void mouseReleaseEvent(QMouseEvent *ev);

signals:

    void clicked( COptionPage* );

};

class COptions_LeftBar : public QAbstractScrollArea {

private:

    QList<COptions_Label*>   m_items;
    QWidget                  m_mainWidget;
    QVBoxLayout              m_mainWidgetLay;

    int                      m_itemDimension;

public:

    COptions_LeftBar();

    void    addItem( COptionPage* );

    int     itemDimension(){return m_itemDimension;}
    void    setItemDimension(int dim);
};


#define     OPTIONS_FILENAME    "user_options.cfg"

class COptions : public QDialog {

    Q_OBJECT

private:

    COptions_LeftBar        m_leftArea;
    QList<COptionPage*>     m_pages;
    QAbstractScrollArea     m_optArea;

public:

    COptions();
    void    addPage( COptionPage* );

public slots:

    void    pageClicked( COptionPage* );
    void    applyClicked();

};

#endif // COPTIONS_H
