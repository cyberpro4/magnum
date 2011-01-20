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

#ifndef CCODEEDITOR_H
#define CCODEEDITOR_H

#include <QtGui>
#include "cfilesyntaxhighlighter.h"
#include "ccodeeditor_foldarea.h"

class CCodeEditor_LineNumberArea;
class CDocument;

#define     SYNTAX_SYSTEMFILE       "system.xml"

class CCodeEditor : public QPlainTextEdit {

	Q_OBJECT

	friend class CCodeEditor_FoldArea;

public:
	CCodeEditor(QWidget *parent = 0);
	~CCodeEditor();

        int     m_oldBlockCount;

	void lineNumberAreaPaintEvent(QPaintEvent *event);
	int lineNumberAreaWidth();

	void setDocumentOwner(CDocument* );
	CDocument* documentOwner();

	void	foldBlocks( int line_start , int line_end );

protected:
	void resizeEvent(QResizeEvent *event);

private slots:
	void updateLineNumberAreaWidth(int newBlockCount);
	void highlightCurrentLine();
	void updateLineNumberArea(const QRect &, int);

private:

	QWidget *lineNumberArea;
	CCodeEditor_FoldArea* m_foldArea;
	CDocument*  m_ownerDocument;
};


#include "ccodeeditor_linenumberarea.h"
#include "cdocument.h"

#endif // CCODEEDITOR_H
