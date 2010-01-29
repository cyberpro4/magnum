#ifndef CPROJECTFUNCTION_H
#define CPROJECTFUNCTION_H

#include "cprojecttype.h"

class CProjectFunction:public CProjectItem{
#warning INSERIRE I PARAMETRI DEI CPROJECTFUNCTION
public:
    CProjectFunction( CPROJECTITEM_PARAMS, CProjectType* retType );

private:
    CProjectType*       m_returnType;

};

#endif // CPROJECTFUNCTION_H
