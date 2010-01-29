#include "cprojecttype.h"

CProjectType::CProjectType( CPROJECTITEM_PARAMS , QList<CProjectType*> subTypes )
    :CProjectItem(CPROJECTITEM_VARS){

    m_subTypes.append( subTypes );

}
