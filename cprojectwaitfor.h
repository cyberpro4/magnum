#ifndef CPROJECTWAITFOR_H
#define CPROJECTWAITFOR_H


#include "cprojectitem.h"
#include "cprojectwaitsec.h"

#define CPROJECTITEM_REGEXPR_FOR                 QString("[Ff]{1}[Oo]{1}[Rr]{1}")
#define CPROJECTITEM_REGEXPR_WAIT_FOR            CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB+CPROJECTITEM_REGEXPR_WAIT+CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB+CPROJECTITEM_REGEXPR_FOR+CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB


class CProjectWaitFor:public CProjectItem{

public:
    CProjectWaitFor(CPROJECTITEM_PARAMS);

    static bool         isIt( QTextBlock* block );

    QString             condition(){ return m_condition; }

private:
    QString       m_condition;

};

#endif // CPROJECTWAITFOR_H
