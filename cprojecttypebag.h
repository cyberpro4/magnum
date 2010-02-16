#ifndef CPROJECTTYPEBAG_H
#define CPROJECTTYPEBAG_H

#include <QtCore>

class CProjectTypeBag{
public:
    CProjectTypeBag();

    void    addType( QString s );

    QList<QString>* getTypeList( );

public:
    static CProjectTypeBag*     m_staticInstance;

private:
    QList<QString>      m_typeList;

};

#define CPROJECT_TYP_BAG    CProjectTypeBag::m_staticInstance;

#endif // CPROJECTTYPEBAG_H
