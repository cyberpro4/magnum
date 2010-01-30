#ifndef CCODEEDITOR_H
#define CCODEEDITOR_H

#include <QtGui>
#include "cfilesyntaxhighlighter.h"

class CCodeEditor_LineNumberArea;
class CDocument;

class CCodeEditor : public QPlainTextEdit {

	Q_OBJECT

public:
	CCodeEditor(QWidget *parent = 0);
	~CCodeEditor();


	void lineNumberAreaPaintEvent(QPaintEvent *event);
	int lineNumberAreaWidth();

	void setDocumentOwner(CDocument* );
	CDocument* documentOwner();

protected:
	void resizeEvent(QResizeEvent *event);

private slots:
	void updateLineNumberAreaWidth(int newBlockCount);
	void highlightCurrentLine();
	void updateLineNumberArea(const QRect &, int);

private:

	QWidget *lineNumberArea;
	CDocument*  m_ownerDocument;
};


#include "ccodeeditor_linenumberarea.h"
#include "cdocument.h"

#endif // CCODEEDITOR_H
