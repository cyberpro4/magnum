#ifndef CCODEEDITOR_H
#define CCODEEDITOR_H

#include <QtGui>
#include "cfilesyntaxhighlighter.h"

class LineNumberArea;

class CCodeEditor : public QPlainTextEdit {

	Q_OBJECT

public:
	CCodeEditor(QWidget *parent = 0);
	~CCodeEditor();


	void lineNumberAreaPaintEvent(QPaintEvent *event);
	int lineNumberAreaWidth();

protected:
	void resizeEvent(QResizeEvent *event);

private slots:
	void updateLineNumberAreaWidth(int newBlockCount);
	void highlightCurrentLine();
	void updateLineNumberArea(const QRect &, int);

private:
	QWidget *lineNumberArea;
};

class LineNumberArea : public QWidget {

public:
	LineNumberArea(QWidget *editor) : QWidget(editor) {
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

#endif // CCODEEDITOR_H
