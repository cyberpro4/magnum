#ifndef CFILESYNTAXHIGHLIGHTER_H
#define CFILESYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class CFileSyntaxHighlighter : public QSyntaxHighlighter {

public:
	CFileSyntaxHighlighter(QTextDocument*);
	~CFileSyntaxHighlighter();

	void highlightBlock(const QString &text);

};

#endif // CFILESYNTAXHIGHLIGHTER_H
