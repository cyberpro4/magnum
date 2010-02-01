#ifndef CPROJECTFILE_H
#define CPROJECTFILE_H

#include "cprojectitem.h"
#include "cprojectitemfactory.h"

class CProjectFile:public CProjectItem{
public:
    CProjectFile( QString label, CPROJECTITEM_PARAMS );

    QTextBlock* scan( QTextBlock* b );

};

#endif // CPROJECTFILE_H
