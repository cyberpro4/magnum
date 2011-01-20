/**************************************************************************

    Copyright (C) 2011 Claudio Cannatà.

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Magnum.  If not, see <http://www.gnu.org/licenses/>.

**************************************************************************/

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
