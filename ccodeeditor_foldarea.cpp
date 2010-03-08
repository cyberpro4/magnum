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
        QStyleOption opt;
        opt.initFrom( this );
        opt.rect = QRect( 0 , top , width() , bottom - top );

            if (block.isVisible() && bottom >= event->rect().top() && !block.next().isVisible() ) {
                opt.state = QStyle::State_Item | QStyle::State_Children;
            }

            CMagnum_TextBlock* ublock = dynamic_cast<CMagnum_TextBlock*>(block.next().userData());
            if( block.isVisible() && ublock != 0 && block.next().isVisible() ){
                if( ublock->foldable() != -1 ){
                    opt.state = QStyle::State_Item | QStyle::State_Children | QStyle::State_Open | QStyle::State_Sibling;
                }

            }

            ublock = dynamic_cast<CMagnum_TextBlock*>(block.userData());
            if( ublock != 0 && block.isVisible() && block.next().isVisible() ){
                if( ublock->parentFold() != -1 ){

                    QTextBlock bn(block.next());
                    CMagnum_TextBlock* nublock = CMagnum_TextBlock::getDataByBlock( &bn );

                    if( nublock->parentFold() == -1 ){
                        opt.state = QStyle::State_Item ;
                    } else {
                        opt.state = QStyle::State_Sibling;
                    }
                }
            }

            style()->drawPrimitive( QStyle::PE_IndicatorBranch , &opt , &painter , this );


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
