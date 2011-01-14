#ifndef COPTIONPAGE_H
#define COPTIONPAGE_H

#include <QtGui>

class COptionPage : public QWidget {

    Q_OBJECT

public:
    COptionPage(QWidget *parent = 0);

    virtual void        loadSettings(const QMap<QString,QVariant>& values ){}
    virtual void        saveSettings( QMap<QString,QVariant>& ){}

    virtual QPixmap     getLeftBarPixmap(){return QPixmap();}
    virtual QString     getLeftBarDescription(){return "NULL";}

signals:

public slots:

};

#endif // COPTIONPAGE_H
