#ifndef CPROJECT_H
#define CPROJECT_H

#include <QtCore>
#include "cdocument.h"
#include "cprojectfile.h"
#include "cprojecttypebag.h"

class CProject:public QObject{
    Q_OBJECT
public:
    CProject();

    void documentPush( CDocument* document );

private:
    QList<CDocument*>       m_documentList;
    QList<CProjectFile*>    m_childList;
    QString                 m_name;
    QString                 m_location;

    CProjectTypeBag*        m_typeBag;

public slots:
    void documentChanged();

};

#endif // CPROJECT_H
