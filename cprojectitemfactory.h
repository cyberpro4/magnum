#ifndef CPROJECTITEMFACTORY_H
#define CPROJECTITEMFACTORY_H

#include "cdocument.h"

#include "cprojectitem.h"
#include "cprojectfunction.h"
#include "cprojectinstruction.h"
#include "cprojecttype.h"
#include "cprojectvariable.h"
#include "cprojectprocedure.h"
#include "cprojectwaitsec.h"

class CProjectItemFactory{
public:
    CProjectItemFactory();
    static CProjectItem* buildItem( CDocument* document, QTextBlock* b, CProjectItem* parent );
};

#endif // CPROJECTITEMFACTORY_H
