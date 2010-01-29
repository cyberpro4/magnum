#ifndef CPROJECTVARIABLE_H
#define CPROJECTVARIABLE_H

#include "cprojectitem.h"
#include "cprojecttype.h"

class CProjectVariable:public CProjectItem{

public:
    CProjectVariable( CProjectType* type, CPROJECTITEM_PARAMS );

    CProjectType*       type(){     return m_type;}

private:
    CProjectType*       m_type;

};

#endif // CPROJECTVARIABLE_H
