#ifndef CPROJECT_H
#define CPROJECT_H

#include <QtCore>
#include "cdocument.h"

class CProject{

public:
    CProject();

private:
    QList<CDocument*>       m_documentList;
    QString                 m_name;
    QString                 m_location;

};

#endif // CPROJECT_H
