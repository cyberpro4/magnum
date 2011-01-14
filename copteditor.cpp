#include "copteditor.h"

COptEditor::COptEditor(){
    setupUi( this );

    uiFontFamily->insertItems( 0 , QFontDatabase().families() );
    uiFontSize->setValidator( new QIntValidator( 8 , 72 , this ) );
}

void COptEditor::loadSettings(const QMap<QString, QVariant> &values){
    uiFontSize->setText( values["editor/fontSize"].toString() );
    uiFontFamily->setCurrentIndex( uiFontFamily->findText( values["editor/fontFamily"].toString() ) );
}

void COptEditor::saveSettings(QMap<QString, QVariant> &values){
    values["editor/fontSize"] = uiFontSize->text();
    values["editor/fontFamily"] = uiFontFamily->currentText();
}
