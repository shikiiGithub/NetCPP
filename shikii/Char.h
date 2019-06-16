#pragma once 
#include <iostream>
#include "Object.h"
namespace System
{class Char :public Object
	{

		_Char * ch_Arr ;
	private:
		void Init()
		{
#ifndef ANSI
			this->TypeName =L"Char" ;
#else
			this->TypeName ="Char" ;
#endif
			ch_Arr = new _Char[1] ;
		}
	public:
		Char()
		{
			Init() ;
		}
		Char(_Char& ch)
		{
			Init() ;
			ch_Arr[0]=ch ;

		}

		void operator = (_Char& ch)
		{
			ch_Arr[0] =ch ;
		}
		virtual bool operator == (Object & obj)
		{
			if(Object::operator ==(obj))
			{
				Char * Ch  = dynamic_cast<Char *>(&obj);
				return this->operator==(Ch->ch_Arr[0]) ;
			}
			else
				return false ;
		}
		virtual bool operator ==(_Char & ch)
		{
			return this->ch_Arr[0]==ch ;
		}
		operator _Char()
		{
			return ch_Arr[0] ;
		}
		virtual const PtrSTR  ToString()
		{
			return ch_Arr ;
		}
	};
}
