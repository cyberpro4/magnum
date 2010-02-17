#ifndef CPROJECTWAITSEC_H
#define CPROJECTWAITSEC_H

#include "cprojectitem.h"

#define CPROJECTITEM_REGEXPR_WAIT                QString("[Ww]{1}[Aa]{1}[Ii]{1}[Tt]{1}")
#define CPROJECTITEM_REGEXPR_SEC                 QString("[Ss]{1}[Ee]{1}[Cc]{1}")
#define CPROJECTITEM_REGEXPR_WAIT_SEC            CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB+CPROJECTITEM_REGEXPR_WAIT+CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB+CPROJECTITEM_REGEXPR_SEC


class CProjectWaitSec:public CProjectItem{

public:
    CProjectWaitSec(CPROJECTITEM_PARAMS);

    static bool         isIt( QTextBlock* block );

    QString             secs(){ return m_secs; };

private:
    QString       m_secs;

};

#endif // CPROJECTWAITSEC_H
