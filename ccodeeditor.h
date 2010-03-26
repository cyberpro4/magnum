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
