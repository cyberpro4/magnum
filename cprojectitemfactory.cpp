#include "cprojectitemfactory.h"

CProjectItemFactory::CProjectItemFactory(){

}

CProjectItem* CProjectItemFactory::buildItem( CDocument* document, QTextBlock* b, CProjectItem* parent ){
    if( CProjectFunction::isIt( b ) ){
        return new CProjectFunction( document, b, parent );
    }else if( CProjectProcedure::isIt( b ) ){
        return new CProjectProcedure( document, b, parent );
    }else if( CProjectVariable::isIt( b ) ){
        return new CProjectVariable(document, b, parent );
    }
    return NULL;
}
