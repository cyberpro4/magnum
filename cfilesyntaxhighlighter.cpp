#include "cfilesyntaxhighlighter.h"

CFileSyntaxHighlighter::CFileSyntaxHighlighter(QTextDocument* parent) : QSyntaxHighlighter(parent){
}

CFileSyntaxHighlighter::~CFileSyntaxHighlighter(){

    CFileSyntaxHighlighter_Format* form;
    QRegExp* exp;

    foreach( form , m_formats ){
        foreach( exp , form->m_regsExp ){
            delete exp;
        }

        delete form;
    }
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

        QDomNodeList list = cur.elementsByTagName( "REGEXP" );
        for(int node=0;node < list.size();node++){
            toSave->m_regsExp.append( new QRegExp( list.at(node).toElement().attribute("PATTERN","") ) );
        }

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
    QRegExp* exp;

    foreach( form , m_formats ){
        foreach( exp , form->m_regsExp ){

            int index = text.indexOf( *exp );

            while (index >= 0) {

                int length = exp->matchedLength();

                if( length == 0 )
                    break;

                setFormat(index, length, form->m_format );
                index = text.indexOf( *exp , length > 0 ? index+length : index + 1);

            }
        }
    }
}
