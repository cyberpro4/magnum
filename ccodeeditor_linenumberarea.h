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

#ifndef CCODEEDITOR_LINENUMBERAREA_H
#define CCODEEDITOR_LINENUMBERAREA_H

#include "ccodeeditor.h"

class CCodeEditor_LineNumberArea : public QWidget {

public:
	CCodeEditor_LineNumberArea(QWidget *editor) : QWidget(editor) {
		codeEditor = (CCodeEditor*)editor;
	}

	QSize sizeHint() const {
		return QSize(codeEditor->lineNumberAreaWidth(), 0);
	}

protected:
	void paintEvent(QPaintEvent *event) {
		codeEditor->lineNumberAreaPaintEvent(event);
	}

private:
	CCodeEditor *codeEditor;
};

#endif // CCODEEDITOR_LINENUMBERAREA_H
