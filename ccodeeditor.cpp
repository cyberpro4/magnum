#include "ccodeeditor.h"

CCodeEditor::CCodeEditor(QWidget *parent)
	: QPlainTextEdit(parent) {
	lineNumberArea = new CCodeEditor_LineNumberArea(this);
	m_foldArea = new CCodeEditor_FoldArea( this );

	connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));

	connect(this, SIGNAL(updateRequest(const QRect &, int)), this, SLOT(updateLineNumberArea(const QRect &, int)));

	connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));

	updateLineNumberAreaWidth(0);
	highlightCurrentLine();

	setFont( QFont( "Courier New" , 11 ) );

	CFileSyntaxHighlighter* s = new CFileSyntaxHighlighter( this->document() );
        s->loadFromFile( "kuka_syntax.xml" );

        // This second loading fail and cause to lost of first
        // syntax file ( TODO )
        /*s = new CFileSyntaxHighlighter( this->document() );
        s->loadFromFile( SYNTAX_SYSTEMFILE );*/

	m_ownerDocument = NULL;
        m_oldBlockCount = 0;
}

CDocument* CCodeEditor::documentOwner(){
    return m_ownerDocument;
}

void CCodeEditor::setDocumentOwner( CDocument* doc ){
    m_ownerDocument = doc;
}

int CCodeEditor::lineNumberAreaWidth() {
	int digits = 1;
	int max = qMax(1, blockCount());

	while (max >= 10) {
		max /= 10;
		++digits;
	}

	int space = 3 + fontMetrics().maxWidth() * digits;

	return space + 10;
}

void CCodeEditor::foldBlocks( int line_start , int line_end ){
    QTextBlock bstart = document()->findBlockByLineNumber( line_start );

    if( !bstart.isValid())
	return;

    for(int i=line_start; i<line_end && bstart.isValid() ;i++){
	bstart.setVisible( false );
	bstart = bstart.next();
    }

    viewport()->update();
    lineNumberArea->update();
    m_foldArea->update();
}

void CCodeEditor::updateLineNumberAreaWidth(int newBlockCount){
	setViewportMargins(lineNumberAreaWidth()+m_foldArea->foldAreaWidth(), 0, 0, 0);

        // CHECK FOR PREVIUOS BLOCK INDENT

        if( newBlockCount == 0 ){
            return;
        }

        // the block count has increased?
        if( (newBlockCount-1) == m_oldBlockCount ){

            if( !textCursor().block().isValid() ){
                m_oldBlockCount = newBlockCount;
                return;
            }

            if( textCursor().block().previous().isValid() ){

                // Pick the previous block text and his
                // indent manually
                QString     prevText = textCursor().block().previous().text();
                QString     oldIndent;
                int         cc = 0;

                while( cc < prevText.length() ){
                    if( prevText[cc] == ' ' || prevText[cc] == '\t' )
                        oldIndent += prevText[cc];
                    else
                        break;

                    cc++;
                }

                // and apply on current cursor position
                if( oldIndent.length() > 0 && textCursor().atBlockStart() ){
                    textCursor().insertText( oldIndent );
                }
            }
        }

        m_oldBlockCount = newBlockCount;

}



void CCodeEditor::updateLineNumberArea(const QRect &rect, int dy) {
    if (dy){
	lineNumberArea->scroll(0, dy);
	m_foldArea->scroll(0, dy);
    } else {
	lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());
	m_foldArea->update(0, rect.y(), m_foldArea->width(), rect.height());
    }

    if (rect.contains(viewport()->rect()))
	updateLineNumberAreaWidth(0);
}



void CCodeEditor::resizeEvent(QResizeEvent *e) {
	QPlainTextEdit::resizeEvent(e);

	QRect cr = contentsRect();
	int lnaw = lineNumberAreaWidth();

	lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lnaw , cr.height()));

	m_foldArea->setGeometry(QRect(cr.left()+lnaw, cr.top(), m_foldArea->foldAreaWidth() , cr.height()));
}



void CCodeEditor::highlightCurrentLine(){

	QList<QTextEdit::ExtraSelection> extraSelections;

	if (!isReadOnly()) {
		QTextEdit::ExtraSelection selection;

		QColor lineColor = QColor(Qt::blue).lighter(190);

		selection.format.setBackground(lineColor);
		selection.format.setProperty(QTextFormat::FullWidthSelection, true);
		selection.cursor = textCursor();
		selection.cursor.clearSelection();
		extraSelections.append(selection);
	}

	setExtraSelections(extraSelections);
}



void CCodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
	QPainter painter(lineNumberArea);
	painter.fillRect(event->rect(), QColor(Qt::lightGray).lighter( 120 ) );


	QTextBlock block = firstVisibleBlock();
	int blockNumber = block.blockNumber();
	int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
	int bottom = top + (int) blockBoundingRect(block).height();

	while (block.isValid() && top <= event->rect().bottom()) {
		if (block.isVisible() && bottom >= event->rect().top()) {
			QString number = QString::number(blockNumber + 1);

			painter.setPen( QColor( Qt::lightGray ).lighter( 70 ) );
			painter.drawText(0, top, lineNumberArea->width() - 2, fontMetrics().height(),
					 Qt::AlignRight, number);
		}

		block = block.next();
		top = bottom;
		bottom = top + (int) blockBoundingRect(block).height();
		++blockNumber;
	}
}

CCodeEditor::~CCodeEditor(){

    delete m_foldArea;
    delete lineNumberArea;
}
