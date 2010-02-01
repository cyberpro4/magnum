#ifndef CPROJECTPROCEDURE_H
#define CPROJECTPROCEDURE_H

#include "cprojectitem.h"
#include "cprojecttype.h"
#include "cprojectitemfactory.h"

class CProjectProcedure:public CProjectItem{
public:
    CProjectProcedure( CPROJECTITEM_PARAMS );

    QTextBlock* scan( QTextBlock* b );
    static bool isIt( QTextBlock* block );

private:
    QList<CProjectType*>    m_paramsList;

};

#endif // CPROJECTPROCEDURE_H
