#include "cfilesyntaxhighlighter.h"

CFileSyntaxHighlighter::CFileSyntaxHighlighter(QTextDocument* parent) : QSyntaxHighlighter(parent){
}

CFileSyntaxHighlighter::~CFileSyntaxHighlighter(){

}

bool CFileSyntaxHighlighter::loadFromFile(const QString & file ){
    QFile f(file);

    if( !f.open( QIODevice::ReadOnly ) ) return false;

    QDomDocument doc;
    doc.setContent( &f );
    f.close();

    QDomElement formats( doc.firstChildElement("FORMATS") );
    QDomElement cur;

    cur = formats.firstChildElement();

    do {

	CFileSyntaxHighlighter_Format* toSave = new CFileSyntaxHighlighter_Format;

	qDebug() << "format: " << cur.attribute("NAME" , "NONE");

	if( cur.elementsByTagName( "REGEXP" ).size() > 0 )
	    toSave->m_regExp.setPattern( cur.elementsByTagName( "REGEXP" ).at(0).toElement().attribute("PATTERN","") );

	if( cur.elementsByTagName( "COLOR").size() > 0 ){
	    QDomElement color = cur.elementsByTagName("COLOR").at(0).toElement();
	    toSave->m_format.setForeground( QBrush( QColor( color.attribute("FOREGROUND" , "#000000") ) ) );
	    toSave->m_format.setBackground( QBrush( QColor( color.attribute("BACKGROUND" , "#FFFFFF") ) ) );
	}

	m_formats.append( toSave );

    } while( !( cur = formats.nextSiblingElement() ).isNull() );

    return true;
}

void CFileSyntaxHighlighter::highlightBlock(const QString &text){

    CFileSyntaxHighlighter_Format* form;

    foreach( form , m_formats ){

	int index = text.indexOf( form->m_regExp );

	while (index >= 0) {

	    int length = form->m_regExp.matchedLength();

	    if( length == 0 )
		break;

	    setFormat(index, length, form->m_format );
	    index = text.indexOf(form->m_regExp, length > 0 ? index+length : index + 1);

	}
    }
}
