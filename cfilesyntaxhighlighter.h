/**************************************************************************

    Copyright (C) 2011 Claudio Cannatà.

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Magnum.  If not, see <http://www.gnu.org/licenses/>.

**************************************************************************/

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
