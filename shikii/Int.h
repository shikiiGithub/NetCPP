#pragma once 
 #include "Number.h"
namespace  System {
    class Int : public Number<int> {
        //protected:
        /* virtual   void Parse(const PtrSTR cStr)
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
         }*/
    public:
        Int() { SetNumberKind(); }

        Int(double n) {
            Value = (int) n;
            NumberValue = n;
            SetNumberKind();
        }

          operator int()
                {
                    return (int)NumberValue ;
                }
        Int(  int n) {
            Value = n;
            NumberValue = Value;
            SetNumberKind();
        }
        Int(  int& n) {
            Value = n;
            NumberValue = Value;
            SetNumberKind();
        }
        Int(CPtrSTR str) {
            Parse(str);
            NumberValue = Value;
            SetNumberKind();
        }

        int operator=(const int n) {
            this->Value = n;
            return Value;
        }

        int operator=(const double & n) {
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

        virtual const PtrSTR ToString() {
#ifndef ANSI
            SPRINTF(chArr,L"%d",Value) ;
#else
            SPRINTF(chArr, "%d", Value);
#endif
            return chArr;
        }

        virtual Object &Invoke(Object *Objs, int n) {

        }

    protected:
        virtual void SetNumberKind() {

#ifndef ANSI
            this->NumberKind = L"int" ;
#else
            this->NumberKind = "int";
#endif

        }

    };
    typedef  Int& int32 ;
}
//  virtual   Int &  operator + (double n) 
//         {
//               vct_ptrBox.push_back(  new Int (lfBaseValue + n) ) ;
//               return *(vct_ptrBox[vct_ptrBox.size()-1]) ;
//         }
//        virtual  Int& operator - (double n)
//         { 
//           vct_ptrBox.push_back(new Int (lfBaseValue - n)) ;
//           return *(vct_ptrBox[vct_ptrBox.size()-1]) ;
//         }
//       virtual Int& operator * (double n)
//         {
//           vct_ptrBox.push_back(new Int (lfBaseValue * n)) ;
//               return *(vct_ptrBox[vct_ptrBox.size()-1]) ;
//         }
//       virtual   Int& operator /(double n)
//         {
//            vct_ptrBox.push_back(new Int (lfBaseValue / n)) ;
//              return *(vct_ptrBox[vct_ptrBox.size()-1]) ;
//         }
     //  virtual   Int& operator +(Object & obj)
      //  {
            
      //       return  *(new Int (lfBaseValue + n.Value)) ;
      //  }
      //  virtual  Int& operator - (Object & obj)
      //   {
      //     return  *(new Int (lfBaseValue - n.Value)) ;
      //   }
      // virtual     Int& operator * (Object & obj)
      //   {
      //           return  *(new Int (lfBaseValue * n.Value)) ;
      //   }
      // virtual   Int& operator /(Object & obj)
      //   {
      //      return  *(new Int (lfBaseValue / n.Value)) ;
      //   }