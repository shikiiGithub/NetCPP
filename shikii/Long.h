#pragma once 
 #include "Number.h"
namespace System {
    class Long : public Number<long> {


    public:
        Long() { SetNumberKind(); }

        Long(double n) {
            Value = (long) n;
            NumberValue = n;
            SetNumberKind();
        }

        Long(long n) {
            Value = n;
            NumberValue = Value;
            SetNumberKind();
        }

        Long(const PtrSTR str) {
            Parse(str);
            NumberValue = Value;
            SetNumberKind();
        }

        float operator=(float n) {
            this->Value = n;
            return Value;
        }

        void operator=(const PtrSTR cStr) {
            Parse(cStr);
        }

        void operator=(const TString &tStr) {
            Parse(tStr);
        }

        void operator=(const System::String &str) {
            Parse(str);
        }

        virtual const PtrSTR ToString() {
#ifndef ANSI
            SPRINTF(chArr,L"%ld",Value) ;
#else
            SPRINTF(chArr, "%ld", Value);
#endif
            return chArr;
        }

        virtual Object &Invoke(Object *Objs, int n) {

        }

    protected:
        virtual void SetNumberKind() {
#ifndef ANSI
            this->NumberKind = L"long" ;
#else
            this->NumberKind = "long";
#endif
        }

    };
}