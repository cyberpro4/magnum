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
    }else if( CProjectWaitSec::isIt( b ) ){
        return new CProjectWaitSec(document, b, parent );
    }else if( CProjectWaitFor::isIt( b ) ){
        return new CProjectWaitFor(document, b, parent );
    }else if( CProjectInterruptDecl::isIt( b ) ){
        return new CProjectInterruptDecl(document, b, parent );
    }
    return NULL;
}
