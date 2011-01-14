#include "coptgeneral.h"

COptGeneral::COptGeneral(){
    setupUi( this );
}

void COptGeneral::loadSettings(const QMap<QString, QVariant> &values){

    genNewDocumentStartup->setChecked( values["global/freshDocumentStartup"].toBool() );

    genNumberRecentFiles->setValue( values["global/MaxNumberRecentFiles"].toInt() );
}

void COptGeneral::saveSettings(QMap<QString, QVariant> &values){
    values["global/freshDocumentStartup"] = QVariant( genNewDocumentStartup->isChecked() );
    values["global/MaxNumberRecentFiles"] = genNumberRecentFiles->value();
}
