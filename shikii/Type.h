#pragma once
#include "IO.h"
#include "Digitals.h"
namespace System
{
	class Type
	{
	public:

		static Object& CreateInstance(PtrSTR ClassName)
		{
#ifndef ANSI
			if(STRCMP(ClassName,L"String")==0)
			{
				return *(new String()) ;
			}
			if(STRCMP(ClassName,L"Char")==0)
			{
				return *(new Char()) ;
			}
			if(STRCMP(ClassName,L"BinaryReader")==0)
			{
				return *(new System::IO::BinaryReader()) ;
			}
			if(STRCMP(ClassName,L"BinaryWriter")==0)
			{
				return *(new System::IO::BinaryReader()) ;
			}

#endif

		}

	};
}
