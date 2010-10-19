#ifndef CCODECOMPLETER_H
#define CCODECOMPLETER_H

#include "cwordcompleter.h"
#include "cprojectfile.h"

class CCodeCompleter : public CWordCompleter {

public:
    CCodeCompleter();

    void complete(CCodeEditor * , CProjectFile* );
};

#endif // CCODECOMPLETER_H
