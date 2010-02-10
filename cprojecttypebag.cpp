#include "cprojecttypebag.h"

CProjectTypeBag* CProjectTypeBag::m_staticInstance;

CProjectTypeBag::CProjectTypeBag(){
    m_typeList.clear();
    addType( "int" );
    addType( "e6pos" );
    addType( "e6axis" );
    m_staticInstance = this;
}
