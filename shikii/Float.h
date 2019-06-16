#pragma once 
 #include "Number.h"
namespace System {
    class Float : public Number<float> {


    public:
        Float() { SetNumberKind(); }

        Float(double n) {
            Value = (float) n;
            NumberValue = n;
            SetNumberKind();
        }

        Float(float n) {
            Value = n;
            NumberValue = Value;
            SetNumberKind();
        }

        Float(const PtrSTR str) {
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
            SPRINTF(chArr,L"%f",Value) ;
#else
            SPRINTF(chArr, "%f", Value);
#endif
            return chArr;
        }

        virtual Object &Invoke(Object *Objs, int n) {

        }

    protected:
        virtual void SetNumberKind() {
#ifndef ANSI
            this->NumberKind = L"float" ;
#else
            this->NumberKind = "float";
#endif
        }

    };
}
  //  virtual   Float& operator + (Object & obj)
      //  {
      //       Float & n = * (dynamic_cast<Float *>(&obj)) ;
      //       return  *(new Float (lfBaseValue + n.Value)) ;
      //  }
      //  virtual  Float& operator - (Object &  obj)
      //   {
      //      Float & n = * (dynamic_cast<Float *>(&obj)) ;
      //     return  *(new Float (lfBaseValue - n.Value)) ;
      //   }
      // virtual     Float& operator * (Object & obj)
      //   {
      //      Float & n = * (dynamic_cast<Float *>(&obj)) ;
      //           return  *(new Float (lfBaseValue * n.Value)) ;
      //   }
      // virtual   Float& operator /(Object &  obj)
      //   {
      //      Float & n = * (dynamic_cast<Float *>(&obj)) ;
      //      return  *(new Float (lfBaseValue / n.Value)) ;
      //   }
       //    virtual   Float &  operator + (double n) 
      //   {
               
      //        vct_ptrBox.push_back(new Float (lfBaseValue + n)) ;
      //        return  *(vct_ptrBox[vct_ptrBox.size()-1]) ;
      //   }
      //  virtual  Float& operator - (double n)
      //   {
      //           vct_ptrBox.push_back(new Float (lfBaseValue - n)) ;
      //            return  *(vct_ptrBox[vct_ptrBox.size()-1]) ;
        
      //   }
      // virtual Float& operator * (double n)
      //   {
      //    vct_ptrBox.push_back(new Float (lfBaseValue * n)) ;
      //       return  *(vct_ptrBox[vct_ptrBox.size()-1]) ;
       
      //   }
      // virtual   Float& operator /(double n)
      //   {
      //     vct_ptrBox.push_back(new Float (lfBaseValue / n)) ;
      //       return  *(vct_ptrBox[vct_ptrBox.size()-1]) ;
      //   }