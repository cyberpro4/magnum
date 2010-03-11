#include "copteditor.h"

COptEditor::COptEditor(){
    QVBoxLayout*    mainvb = new QVBoxLayout();

    QGroupBox*  gb_font = new QGroupBox("Font" );
    QHBoxLayout*    hboxlay = new QHBoxLayout();

    hboxlay->addWidget( &m_fontFamily );
    hboxlay->addWidget( &m_fontSize );

    gb_font->setLayout( hboxlay );

    mainvb->addWidget( gb_font );

    setLayout( mainvb );
}

void COptEditor::loadSettings(const QMap<QString, QVariant> &values){

}

void COptEditor::saveSettings(QMap<QString, QVariant> &){

}
