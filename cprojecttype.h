#ifndef CPROJECTTYPE_H
#define CPROJECTTYPE_H

#include "cprojectitem.h"
#include "cprojecttypebag.h"

/*
"
struct          ([sS][tT][rR][uU][cC]){1}[ \\t]+
nomestrutt      ([0-9_]*[a-zA-Z]+[0-9_]*)+[ \\t]+
tipo            (([0-9_]*[a-zA-Z]+[0-9_]*)+[ \\t]+){1}
nomecampo       ([\\$]{0,1}([0-9_]*[a-zA-Z]+[0-9_]*)+([\\[]{1}[ ]*[0-9]+[ ]*[\\]]{1})*){1}
,altrocampo     ([ \\t]*,([ \\t]*[\\$]{0,1}([0-9_]*[a-zA-Z]+[0-9_]*)+([\\[]{1}[ ]*[0-9]+[ ]*[\\]]{1})*){1})*
da inserire |, tipo altrocampo
"
*/
class CProjectType:public CProjectItem{
public:
    CProjectType( CPROJECTITEM_PARAMS );

};

#endif // CPROJECTTYPE_H
