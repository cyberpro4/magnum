#ifndef CPROJECTINTERRUPTDECL_H
#define CPROJECTINTERRUPTDECL_H

#include "cprojectitem.h"

#define CPROJECTITEM_REGEXPR_GLOBAL              QString("[Gg]{1}[Ll]{1}[Oo]{1}[Bb]{1}[Aa]{1}[Ll]{1}")
#define CPROJECTITEM_REGEXPR_INTERRUPT           QString("[Ii]{1}[Nn]{1}[Tt]{1}[Ee]{1}[Rr]{1}[Rr]{1}[Uu]{1}[Pp]{1}[Tt]{1}")
#define CPROJECTITEM_REGEXPR_DECL                QString("[dD]{1}[eE]{1}[cC]{1}[lL]{1}")
#define CPROJECTITEM_REGEXPR_ID                  QString("[0-9]+")
#define CPROJECTITEM_REGEXPR_WHEN                QString("[Ww]{1}[Hh]{1}[Ee]{1}[Nn]{1}")
#define CPROJECTITEM_REGEXPR_DO                  QString("[Dd]{1}[Oo]{1}")
#define CPROJECTITEM_REGEXPR_INTERRUPT_DECL      CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB+CPROJECTITEM_REGEXPR_INTERRUPT+CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB+CPROJECTITEM_REGEXPR_DECL+CPROJECTITEM_REGEXPR_LAST_ONE_SPACE_TAB


class CProjectInterruptDecl:public CProjectItem{

public:
    CProjectInterruptDecl(CPROJECTITEM_PARAMS);

    static bool         isIt( QTextBlock* block );

    QString             id(){ return m_id; } //interrupt ID
    QString             condition(){ return m_condition; } //interrupt condition
    QString             call(){ return m_call; } //interrupt call code

private:
    QString     m_id;
    QString     m_condition;
    QString     m_call;

};

#endif // CPROJECTINTERRUPTDECL_H
