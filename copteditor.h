#ifndef COPTEDITOR_H
#define COPTEDITOR_H

#include "coptionpage.h"
#include "ui_setup_editor.h"

class COptEditor : public COptionPage , private Ui::setupEditor {

protected:

public:
    COptEditor();

    QPixmap     getLeftBarPixmap(){ return QPixmap( ":opt_editor" ); }
    QString     getLeftBarDescription(){ return "Editor"; }

    QString     getUniqueKey(){return "COPTEDITOR";}

    void        loadSettings(const QMap<QString, QVariant> &values);
    void        saveSettings(QMap<QString, QVariant> &);
};

#endif // COPTEDITOR_H
