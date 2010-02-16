#ifndef CPROJECTVARIABLE_H
#define CPROJECTVARIABLE_H

#include "cprojectitem.h"
#include "cprojecttype.h"
#include "cprojecttypebag.h"

#define CPROJECTITEM_REGEXPR_VARNAME                QString("[\\$]{0,1}([0-9_]*[a-zA-Z]+[0-9_]*)+([\\[]{1}[ ]*[0-9]+[ ]*[\\]]{1})*")
#define CPROJECTITEM_REGEXPR_DECL                   QString("([dD]{1}[eE]{1}[cC]{1}[lL]{1}([ \\t]+)){0,1}")
#define CPROJECTITEM_REGEXPR_TYPE                   QString("([^| |\\t])([0-9_]*[a-zA-Z]+[0-9_]*)+[ \\t]+")
#define CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB     QString("[ \\t]+")
#define CPROJECTITEM_REGEXPR_DECL_TYPE_VAR          CPROJECTITEM_REGEXPR_DECL + CPROJECTITEM_REGEXPR_TYPE + CPROJECTITEM_REGEXPR_VARNAME

class CProjectVariable:public CProjectItem{

public:
    CProjectVariable( CPROJECTITEM_PARAMS );

    CProjectType*       dataType(){     return m_dataType;}
    static bool         isIt( QTextBlock* block );

private:
    CProjectType*       m_dataType;

};

#endif // CPROJECTVARIABLE_H
