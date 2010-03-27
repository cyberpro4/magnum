#ifndef CPROJECTFUNCTION_H
#define CPROJECTFUNCTION_H

#include "cprojecttype.h"
#include "cprojectitemfactory.h"

class CProjectFunction:public CProjectItem{
#warning INSERIRE I PARAMETRI DEI CPROJECTFUNCTION
public:
    CProjectFunction( CPROJECTITEM_PARAMS );

    QTextBlock* scan( QTextBlock* b );
    static bool isIt( QTextBlock* block );

    QString getFunctionName();

private:
    QString                 m_functionName; //solo nome della funzione

    CProjectType*           m_returnType;
    QList<CProjectType*>    m_paramsList;

};

#endif // CPROJECTFUNCTION_H
