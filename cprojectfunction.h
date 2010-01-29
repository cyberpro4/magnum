#ifndef CPROJECTFUNCTION_H
#define CPROJECTFUNCTION_H

#include "cprojecttype.h"

class CProjectFunction:public CProjectItem{

public:
    CProjectFunction( CPROJECTITEM_PARAMS, CProjectType* retType );

private:
    CProjectType*       m_returnType;

};

#endif // CPROJECTFUNCTION_H
