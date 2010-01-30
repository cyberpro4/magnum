#ifndef CPROJECT_H
#define CPROJECT_H

#include <QtCore>
#include "cdocument.h"
#include "cprojectitem.h"

class CProject:public QObject{
    Q_OBJECT
public:
    CProject();

    void documentPush( CDocument* document );

private:
    QList<CDocument*>       m_documentList;
    QList<CProjectItem*>    m_childList;
    QString                 m_name;
    QString                 m_location;

public slots:
    void documentChanged();

};

#endif // CPROJECT_H
