#pragma once
#include "Array.h"
namespace System
{ namespace Collections
	{
		namespace Generic {

			template<typename K, typename V>
			class Dictionary : public ArrayBase {
			public:
				Array <K> Key;
				Array <V> Value;

				Dictionary() {
					_nSize = 0;
#ifndef ANSI
					this->TypeName = L"Dictionary" ;
#else
					this->TypeName = "Dictionary";
#endif
				}
				virtual Object &Invoke(Object *Objs, int n)
			   {

			   }
				// Fetch Value
				virtual const  V & operator[](K t) {
					int nIndex = Key.IndexOf(t);
					if (nIndex > -1) {
						return Value[nIndex];
					} else
						return NULL;
				}

				//Fetch Key Collection
				virtual K *Pointer() {
					return Key.Pointer();
				}

				virtual void Clear() {
					Key.Clear();
					Value.Clear();

				}

				void AddItem(K &k, V &v) {
					Key.AddItem(k);
					Value.AddItem(v);
				}

				virtual void RemoveAt(int n) {
					Key.RemoveAt(n);
					Value.RemoveAt(n);
				}

				virtual const PtrSTR ToString() {
					return TypeName;
				}

				virtual void Dispose() {
					Key.Dispose();
					Value.Dispose();
				}

				~Dictionary() {
					Dispose();
				}

			};
		}
	}
}
/*
// Fetch Value
virtual const V * operator [](K t)
{
int nIndex=Key.IndexOf(t) ;
if(nIndex>-1)
{
return Value[nIndex] ;
}
else
return NULL;
}
//Fetch Key Collection
virtual K * Pointer()
{
return Key.Pointer() ;
}
*/