#include "copteditor.h"

COptEditor::COptEditor(){
    setupUi( this );

    uiFontFamily->insertItems( 0 , QFontDatabase().families() );
    uiFontSize->setValidator( new QIntValidator( 8 , 72 , this ) );
}

void COptEditor::loadSettings(const QMap<QString, QVariant> &values){
    uiFontSize->setText( values["edi_fontSize"].toString() );
    uiFontFamily->setCurrentIndex( uiFontFamily->findText( values["edi_fontFamily"].toString() ) );
}

void COptEditor::saveSettings(QMap<QString, QVariant> &values){
    values["edi_fontSize"] = uiFontSize->text();
    values["edi_fontFamily"] = uiFontFamily->currentText();
}
