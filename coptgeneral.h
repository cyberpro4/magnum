#ifndef COPTGENERAL_H
#define COPTGENERAL_H

#include "coptionpage.h"
#include "ui_setup_general.h"

class COptGeneral : public COptionPage , private Ui::setupGeneral {

public:
    COptGeneral();

    QPixmap     getLeftBarPixmap(){ return QPixmap( ":opt_general" ); }
    QString     getLeftBarDescription(){ return "General"; }

    QString     getUniqueKey(){return "COPTGENERAL";}

    void        loadSettings(const QMap<QString, QVariant> &values);
    void        saveSettings(QMap<QString, QVariant> &);
};

#endif // COPTGENERAL_H
