#pragma once 
#include<iostream>
#include <sstream>
#include "String.h"
 #include <vector>
namespace System {
	class NumberBase : public Object {

	protected:
		PtrSTR NumberKind;

	public:
		double NumberValue;

		NumberBase() {

		}

		template<typename T>
		T GetValue() {
			return (T) NumberValue;
		}

		virtual bool operator==(Object &obj) {
			if (STRCMP(this->TypeName, obj.TypeName) == 0) {
				NumberBase *numb = dynamic_cast<NumberBase *>(&obj);
				if (numb->NumberValue == NumberValue)
					return true;
				else {
					return false;
				}
			} else
				return false;
		}

	protected:
		virtual void Parse(const PtrSTR cStr) =0;

		virtual void Parse(const TString &tStr) = 0;

		virtual void Parse(const System::String &str) = 0;

		virtual void SetNumberKind()=0;
	};

	template<typename T>
	class Number : public NumberBase {
	protected:
		_Char *chArr;

		T Value;
		TStringStream *ss;

	public:
		Number() {
			ss = new TStringStream();
			chArr = new _Char[50];
#ifndef  ANSI
			this->TypeName =L"Number";
#else
			TypeName = "Number";
#endif

		}

		virtual T operator=(T t) = 0;

		~Number() {

			Dispose();

		}

	protected:
		virtual void Parse(const PtrSTR cStr) {
			(*ss).clear();
			(*ss) << cStr;
			(*ss) >> Value;
		}

		virtual void Parse(const TString &tStr) {
			(*ss).clear();
			(*ss) << tStr;
			(*ss) >> Value;
		}

		virtual void Parse(const System::String &str) {
			(*ss).clear();
			(*ss) << str.str;
			(*ss) >> Value;
		}

		virtual void Dispose() {
			delete[] chArr;
			delete ss;
		}

	};
}
//     virtual NumberBase &operator+(NumberBase   &n) 
//     {
//         lfBaseValue +=
//        UpdateNumber()
//     }

//    virtual NumberBase &operator-(NumberBase     &n) 
//    {

//    }

//    virtual NumberBase &operator*(NumberBase   &n)
//    {
        
//    }

//    virtual NumberBase &operator/(NumberBase   &n)
//    {

//    }
//  void DisposeNumOperatorCache()
//    {
//       int  n =vct_ptrBox.size() ;
//        for   (size_t i = 0; i < n-1 ; i++)
//        {
//            delete vct_ptrBox[i] ;
//        }  
//    }