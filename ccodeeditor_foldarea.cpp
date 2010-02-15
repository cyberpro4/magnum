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
                painter.drawText(0, top, width() - 4, ((CCodeEditor*)parent())->fontMetrics().height(),
                                                        Qt::AlignRight, "+" );
            }

            CMagnum_TextBlock* ublock = dynamic_cast<CMagnum_TextBlock*>(block.next().userData());
            if( block.isVisible() && ublock != 0 ){
                if( ublock->foldable() != -1 ){
                    painter.drawRect( QRect( 5 , top+3 , 11 , 11 ) );
                    painter.drawText(0, top, width() - 4, ((CCodeEditor*)parent())->fontMetrics().height(), Qt::AlignRight, "-" );
                }

            }

            ublock = dynamic_cast<CMagnum_TextBlock*>(block.userData());
            if( ublock != 0 && block.isVisible() && block.next().isVisible() ){
                if( ublock->parentFold() != -1 ){

                    QTextBlock bn(block.next());
                    CMagnum_TextBlock* nublock = CMagnum_TextBlock::getDataByBlock( &bn );

                    if( nublock->parentFold() == -1 ){
                        painter.drawLine( width() / 2 , top , width() / 2 , top+((bottom - top) / 2) );
                        painter.drawLine( width() / 2 , top+((bottom - top) / 2) , width() , top + ((bottom - top) / 2) );
                    } else {
                        painter.drawLine( width() / 2 , top , width() / 2 , bottom );
                    }
                }
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
        thblock.setVisible( true );
        thblock = thblock.next();
    }

    if( dynamic_cast<CMagnum_TextBlock*>(thblock.userData()) != 0 ){
        CMagnum_TextBlock* mudata = dynamic_cast<CMagnum_TextBlock*>(thblock.userData());

        while( thblock.isValid() && thblock.blockNumber() < mudata->foldable() && mudata->foldable() != -1 ){
            thblock.setVisible( false );
            thblock = thblock.next();
        }
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
