#pragma once
#include "Object.h"
namespace System {

    namespace Collection {
        namespace Generic {
            template <typename  T>  class List : Object
           {
               std::vector<T> vct ;
               virtual CPtrSTR ToString()
               {

               }
               virtual Object &Invoke(Object *Objs, int n) =0;

               virtual bool operator==(Object &obj) {

                   if (STRCMP(TypeName, obj.TypeName) == 0)
                       return true;
                   else
                       return false;
               }

               virtual void Dispose()=0;
           };
        }
    }
}