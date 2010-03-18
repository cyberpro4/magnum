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

    Q_OBJECT

private:

    QList<COptions_Label*>   m_items;
    QWidget                  m_mainWidget;
    QVBoxLayout              m_mainWidgetLay;

public:

    COptions_LeftBar();

    void    addItem( COptionPage* );

signals:

    void    itemClicked( COptionPage* );

public slots:

    void    label_clicked( COptionPage* );
};


#define     OPTIONS_FILENAME    "user_options.cfg"

class COptions : public QDialog {

    Q_OBJECT

private:

    static  COptions*       stc_Instance;

    COptions_LeftBar        m_leftArea;
    QList<COptionPage*>     m_pages;

    QAbstractScrollArea     m_optArea;
    QVBoxLayout             m_viewportContainer;

    QMap<QString,QVariant>  m_lastValuesMap;

private:

    void    showPage( COptionPage* );

public:

    COptions();

    static COptions*   getInstance();
    void    addPage( COptionPage* );

    QVariant    getValue(const QString& );

    void    showEvent(QShowEvent *);

public slots:

    void    pageClicked( COptionPage* );
    void    applyClicked();

signals:

    void    optionsChanged();

};

#define OPTIONS     COptions::getInstance()
#define GETOPT(a)      OPTIONS->getValue( a )

#endif // COPTIONS_H
