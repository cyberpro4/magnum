#include "coptgeneral.h"

COptGeneral::COptGeneral(){
    setupUi( this );
}

void COptGeneral::loadSettings(const QMap<QString, QVariant> &values){
    genNewDocumentStartup->setChecked( values["global/freshDocumentStartup"].toBool() );
}

void COptGeneral::saveSettings(QMap<QString, QVariant> &values){
    values["global/freshDocumentStartup"] = QVariant( genNewDocumentStartup->isChecked() );
}
