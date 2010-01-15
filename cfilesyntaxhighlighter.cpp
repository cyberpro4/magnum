#include "cfilesyntaxhighlighter.h"

CFileSyntaxHighlighter::CFileSyntaxHighlighter(QTextDocument* parent) : QSyntaxHighlighter(parent){
}

CFileSyntaxHighlighter::~CFileSyntaxHighlighter(){

}

void CFileSyntaxHighlighter::highlightBlock(const QString &text){
	QTextCharFormat myClassFormat;
	 myClassFormat.setFontWeight(QFont::Bold);
	 myClassFormat.setForeground(Qt::darkMagenta);
	 QString pattern = "\\bMy[A-Za-z]+\\b";

	 QRegExp expression(pattern);
	 int index = text.indexOf(expression);
	 while (index >= 0) {
		 int length = expression.matchedLength();
		 setFormat(index, length, myClassFormat);
		 index = text.indexOf(expression, index + length);
	 }
}
