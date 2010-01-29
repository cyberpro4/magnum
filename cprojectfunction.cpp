#include "cprojectfunction.h"

CProjectFunction::CProjectFunction( CPROJECTITEM_PARAMS, CProjectType* retType ):CProjectItem(CPROJECTITEM_VARS){
    m_returnType = retType;
}
