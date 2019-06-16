#pragma once
#include "Array.h"
#include <vector>
namespace  System

{
	namespace Collections
	{
		namespace Generic
		{
			class StringArray : public ArrayBase {
				_Char **ptr_StrArray;
				std::vector<Array < _Char> >
						vct;

				void Init() {
					ptr_StrArray = NULL;
#ifndef ANSI
					this->TypeName = L"StringArray" ;
        this->ArrayKind = L"StringArray" ;
#else
					this->TypeName = "StringArray";
					this->ArrayKind = "StringArray";
#endif
				}

			public:
				StringArray() {
					Init();
				}

				_Char **Pointer() {
					if (ptr_StrArray != NULL)
						delete[] ptr_StrArray;
					int n = vct.size();
					this->_nSize = n;
					ptr_StrArray = new PtrSTR[n];
					for (int i = 0; i < n; i++) {
						ptr_StrArray[i] = (PtrSTR) vct[i].Pointer();

					}
					return ptr_StrArray;
				}

				virtual void Clear() {
					vct.clear();
				}

				virtual void Dispose() {
					if (ptr_StrArray != NULL)
						delete[] ptr_StrArray;
					Clear();

				}

				virtual const _Char *operator[](int n) {
					return vct[n].Pointer();
				}

				virtual const PtrSTR ToString() {
					return TypeName;
				}

				void AddItem(CPtrSTR tPointer) {
					int nCount = STRLEN(tPointer);
					Array<_Char> arr;
					arr.CopyArray(tPointer, nCount);
					vct.push_back(arr);
					this->_nSize += 1;
				}

				void operator<<(CPtrSTR tPointer) {
					AddItem(tPointer);
				}

				void RemoveAt(int n) {
					std::vector<Array < _Char> > ::iterator
							iter = vct.begin() + n;
					vct.erase(iter);
					this->_nSize = vct.size();
				}

				~StringArray() {
					Dispose();
				}

				virtual Object &Invoke(Object *Objs, int n) {

				}
				/*void AddItem(Object & objArray)
                {
                    ArrayBase * arrBase = dynamic_cast<ArrayBase*>(&objArray) ;
                    this->_nSize = nCount ;
                    Clear() ;
                    for (int i=0;i<_nSize;i++)
                    {
                        Container.push_back((T)(arrBase->operator [i])) ;
                    }

                }*/
			};
#define RefStringArray  StringArray&
		}
	}


}