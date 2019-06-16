#pragma once 
 #include "Number.h"
namespace System {
    class Double : public Number<double> {


    public:
        Double() { SetNumberKind(); }

        Double(double n) {
            Value = (double) n;
            NumberValue = n;
            SetNumberKind();
        }

        Double(const PtrSTR str) {
            Parse(str);
            NumberValue = Value;
            SetNumberKind();
        }

        double operator=(double n) {
            this->Value = n;
            return Value;
        }

        void operator=(const PtrSTR cStr) {
            Parse(cStr);
        }

        void operator=(const TString &tStr) {
            Parse(tStr);
        }

        void operator=(const String &str) {
            Parse(str);
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
        virtual const PtrSTR ToString() {
#ifndef ANSI
            SPRINTF(chArr,L"%lf",Value) ;
#else
            SPRINTF(chArr, "%lf", Value);
#endif
            return chArr;
        }

        virtual Object &Invoke(Object *Objs, int n) {

        }

    protected:
        virtual void SetNumberKind() {
#ifndef ANSI
            this->NumberKind = L"double" ;
#else
            this->NumberKind = "double";
#endif
        }

    };
}

   //virtual   Double &  operator + (double n) 
      //   {
      //        vct_ptrBox.push_back(new Double (lfBaseValue + n)) ;
      //        return  *(vct_ptrBox[vct_ptrBox.size()-1]) ;
      //   }
      //  virtual  Double& operator - (double n)
      //   {
      //           vct_ptrBox.push_back(new Double (lfBaseValue - n)) ;
      //            return  *(vct_ptrBox[vct_ptrBox.size()-1]) ;
        
      //   }
      // virtual Double& operator * (double n)
      //   {
      //    vct_ptrBox.push_back(new Double (lfBaseValue * n)) ;
      //       return  *(vct_ptrBox[vct_ptrBox.size()-1]) ;
       
      //   }
      // virtual   Double& operator /(double n)
      //   {
      //     vct_ptrBox.push_back(new Double (lfBaseValue / n)) ;
      //       return  *(vct_ptrBox[vct_ptrBox.size()-1]) ;
      //   }
        