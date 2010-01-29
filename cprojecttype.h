#ifndef CPROJECTTYPE_H
#define CPROJECTTYPE_H

#include "cprojectitem.h"

class CProjectType:public CProjectItem{
public:
    CProjectType( CPROJECTITEM_PARAMS, QList<CProjectType*> subTypes );

private:
    QList<CProjectType*>    m_subTypes;

};

#endif // CPROJECTTYPE_H
