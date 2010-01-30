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
