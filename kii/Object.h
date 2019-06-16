#pragma once

#include "Macros.h"
class String ;
class Type ;
namespace  System {
    class Object {

    public:
        String * TypeName;
        virtual const String ToString()=0;
         virtual Type GetType()=0 ;
        virtual bool operator==(Object &obj) {
            if (STRCMP(TypeName, obj.TypeName) == 0)
                return true;
            else
                return false;
        }

    };
}