#include "cprojectvariable.h"

CProjectVariable::CProjectVariable( CProjectType* type, CPROJECTITEM_PARAMS )
    : CProjectItem( CPROJECTITEM_VARS ){
    m_type = type;
}
