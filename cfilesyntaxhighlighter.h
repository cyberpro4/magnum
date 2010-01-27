#ifndef CFILESYNTAXHIGHLIGHTER_H
#define CFILESYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QtXml>

class CFileSyntaxHighlighter_Format {
public:
    QTextCharFormat	m_format;
    QList<QRegExp*>	m_regsExp;
};

class CFileSyntaxHighlighter : public QSyntaxHighlighter {

private:

    QList<CFileSyntaxHighlighter_Format*>	m_formats;

public:

    CFileSyntaxHighlighter(QTextDocument*);
    ~CFileSyntaxHighlighter();

    void highlightBlock(const QString &text);

    bool loadFromFile(const QString& );

};

#endif // CFILESYNTAXHIGHLIGHTER_H
