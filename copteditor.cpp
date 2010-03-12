#include "copteditor.h"

COptEditor::COptEditor(){
    QVBoxLayout*    mainvb = new QVBoxLayout();

    QGroupBox*  gb_font = new QGroupBox("Font" );
    QHBoxLayout*    hboxlay = new QHBoxLayout();

    m_fontFamily.insertItems( 0 , QFontDatabase().families() );
    hboxlay->addWidget( &m_fontFamily );

    m_fontSize.setText( "0" );
    hboxlay->addWidget( &m_fontSize );


    gb_font->setLayout( hboxlay );

    mainvb->addWidget( gb_font );

    setLayout( mainvb );
}

void COptEditor::loadSettings(const QMap<QString, QVariant> &values){
    m_fontSize.setText( values["edi_fontSize"].toString() );
    m_fontFamily.setCurrentIndex( m_fontFamily.findText( values["edi_fontFamily"].toString() ) );
}

void COptEditor::saveSettings(QMap<QString, QVariant> &values){
    values["edi_fontSize"] = m_fontSize.text();
    values["edi_fontFamily"] = m_fontFamily.currentText();
}
