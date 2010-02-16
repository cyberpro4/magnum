#include "cprojecttypebag.h"

CProjectTypeBag* CProjectTypeBag::m_staticInstance;

CProjectTypeBag::CProjectTypeBag(){
    m_typeList.clear();
    addType( "int" );
    addType( "e6pos" );
    addType( "e6axis" );
    m_staticInstance = this;
}

void CProjectTypeBag::addType( QString s ){
    if( !m_typeList.contains( s.toUpper() ) )
        m_typeList.append( s.toUpper() );
}

QList<QString>* CProjectTypeBag::getTypeList( ){
    return &m_typeList;
}
