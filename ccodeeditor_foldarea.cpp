#include "ccodeeditor_foldarea.h"
#include "ccodeeditor.h"

CCodeEditor_FoldArea::CCodeEditor_FoldArea(QWidget *parent) :
    QWidget(parent){

    editor = (CCodeEditor*)parent;
}

void CCodeEditor_FoldArea::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    //painter.fillRect(event->rect(), QColor(Qt::lightGray).lighter( 120 ) );


    QTextBlock block = ((CCodeEditor*)parent())->firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) ((CCodeEditor*)parent())->blockBoundingGeometry(block).translated(((CCodeEditor*)parent())->contentOffset()).top();
    int bottom = top + (int) ((CCodeEditor*)parent())->blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom()) {
	    if (block.isVisible() && bottom >= event->rect().top() && !block.next().isVisible() ) {

		    painter.drawText(0, top, width() - 2, ((CCodeEditor*)parent())->fontMetrics().height(),
				     Qt::AlignRight, "+" );
	    }

	    block = block.next();
	    top = bottom;
	    bottom = top + (int) ((CCodeEditor*)parent())->blockBoundingRect(block).height();
	    ++blockNumber;
    }
}

void CCodeEditor_FoldArea::mouseReleaseEvent(QMouseEvent * eve){
    QTextBlock thblock = editor->cursorForPosition( eve->pos() ).block().next();

    while( thblock.isValid() && !thblock.isVisible() ){
	qDebug() << "unfolded!";
	thblock.setVisible( true );
	thblock = thblock.next();
    }

    editor->viewport()->update();
    editor->lineNumberArea->update();
    editor->m_foldArea->update();
}

int CCodeEditor_FoldArea::foldAreaWidth(){
    return 20;
}

void CCodeEditor_FoldArea::updateFolding(int blockCount ){

}
