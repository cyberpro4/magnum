#ifndef CPROJECTTYPEBAG_H
#define CPROJECTTYPEBAG_H

#include <QtCore>

class CProjectTypeBag{
public:
    CProjectTypeBag();

    void    addType( QString s ){
        if( !m_typeList.contains( s.toUpper() ) )
            m_typeList.append( s.toUpper() );
    }

    QList<QString>* getTypeList( ){
        return &m_typeList;
    }

public:
    static CProjectTypeBag*     m_staticInstance;

private:
    QList<QString>      m_typeList;

};

#define CPROJECT_TYP_BAG    CProjectTypeBag::m_staticInstance;

#endif // CPROJECTTYPEBAG_H
