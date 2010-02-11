#include "cmagnum_textblock.h"

CMagnum_TextBlock::CMagnum_TextBlock() {
    m_foldable = -1;
}

CMagnum_TextBlock::~CMagnum_TextBlock() {
}

void CMagnum_TextBlock::setFoldable(int last_line){
    m_foldable = last_line;
}

int CMagnum_TextBlock::foldable(){
    return m_foldable;
}
