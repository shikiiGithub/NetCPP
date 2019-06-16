#pragma once

#include "Object.h"

namespace System
{
    class String :public Object
    {
        std::wstring innerString ;
    public:
        String()
        {
            this->TypeName = new String() ;
           // TypeName->
        }
     String(std::string & str)
     {
            innerString = str ;
     }

    };

}