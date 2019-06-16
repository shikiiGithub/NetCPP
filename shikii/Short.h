#pragma  once
#include "Number.h"
namespace System
{

	class Short :public Number<short>
	{
	 

	public:  
		Short(){  SetNumberKind() ;}
		Short(double n){Value = (short)n ;NumberValue = n ;SetNumberKind() ;}
		Short(long n){Value = n ;NumberValue = Value ;SetNumberKind() ;}
		Short(const PtrSTR str){Parse(str) ;NumberValue = Value ;SetNumberKind() ;}
		short operator = (short n)
		{
			this->Value = n ;
			return Value ;
		} 

		void operator = (const PtrSTR cStr)
		{
			Parse(cStr) ;
		}
		void operator = (const TString& tStr)
		{
			Parse(tStr) ;
		}
		void operator = (const String& str)
		{
			Parse(str) ;
		}
		/*virtual   void Parse(const PtrSTR cStr)
		{
			(*ss).clear() ;
			(*ss)<<cStr ;
			(*ss)>>Value ;
		}
		virtual void Parse(const TString& tStr) 
		{
			(*ss).clear() ;
			(*ss)<<tStr ;
			(*ss)>>Value ;
		}  
		virtual  void Parse(const String& str) 
		{
			(*ss).clear() ;
			(*ss)<<str.str ;
			(*ss)>>Value ;
		} */
		virtual const PtrSTR ToString()
		{
#ifndef ANSI
			SPRINTF(chArr,L"%d",Value) ; 
#else
			SPRINTF(chArr, "%d",Value) ; 
#endif
			return chArr ;
		}
		virtual  Object& Invoke(Object * Objs,int n)
		{

		}
	protected:



		virtual void SetNumberKind()
		{
#ifndef ANSI
			this->NumberKind = L"short" ;
#else
			this->NumberKind = "short" ;
#endif
		}


	};
}
