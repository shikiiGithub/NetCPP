#pragma once
#include "Object.h"
#include <vector>
namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			class ArrayBase : public Object {
			protected:

				int _nSize;

			public:

				PtrSTR ArrayKind;

				ArrayBase() {

				}

				virtual bool operator==(Object &obj) {
					return Object::operator==(obj);
				}

				int Count() {
					return _nSize;
				}

				virtual void Clear()=0;

			};

			template<typename T, typename X>
			class IArray {
			public:

				virtual const T &operator[](X n)=0;

				virtual T *Pointer()=0;

				virtual void RemoveAt(X n)=0;

				virtual int IndexOf(T t)=0;

				virtual void AddItem(T &t)=0;

				virtual void operator<<(T &t) {
					AddItem(t);
				}

				virtual void operator<<(T t) {
					AddItem(t);
				}

			protected:
			private:
			};

			template<typename T>
			class Array : public ArrayBase, public IArray<T, int> {

				void Init() {

					ArrayPointer = NULL;
					_nSize = 0;
					_nPointer_NextElements = 0;
#ifndef ANSI
					this->TypeName = L"Array" ;
#else
					this->TypeName = "Array";
#endif
				}

			protected:
				std::vector<T> Container;
				T *ArrayPointer;
				int _nPointer_NextElements;
			public:
				Array() {
					Init();
				}
               // Make A Static Array Which is Traditional Array,And Provide The First
				//Eelement Pointer
				T *Pointer() {
					if (ArrayPointer != NULL)
						delete[] ArrayPointer;
					int n = Container.size();
					ArrayPointer = new T[n + 1];
					for (int i = 0; i < n; i++) {

						ArrayPointer[i] = Container[i];
					}
					ArrayPointer[n] = 0;
					return ArrayPointer;
				}

				virtual void Clear() {
					if (ArrayPointer != NULL)
						delete[] ArrayPointer;
					Container.clear();
				}

				virtual void Dispose() {
					Clear();
				}

				virtual Object &Invoke(Object *Objs, int n) {

				}

				~Array() {
					Dispose();
				}

				virtual const T &operator[](int n) {
					return Container[n];
				}

				virtual const PtrSTR ToString() {
					return NULL;
				}

				void CopyArray(const T *tPointer, int nCount) {
					Clear();
					for (int i = 0; i < nCount; i++) {
						Container.push_back(tPointer[i]);
					}
					this->_nSize = nCount;
				}

				void CopyArray(Object &objArray) {
					ArrayBase *arrBase = dynamic_cast<ArrayBase *>(&objArray);
					IArray<T, int> *arrMe = dynamic_cast<IArray<T, int> *>(&objArray);
					this->_nSize = arrBase->Count();
					Clear();
					for (int i = 0; i < _nSize; i++) {
						Container.push_back((T) (arrMe->operator[](i)));
					}

				}

				virtual void RemoveAt(int n) {
					Container.erase(Container.begin() + n);
					this->_nSize = Container.size();
				}

				virtual int IndexOf(T t) {
					for (int i = 0; i < _nSize; i++) {
						if (Container[i] == t)
							return i;
					}
					return -1;
				}

				virtual void AddItem(T &t) {
					this->Container.push_back(t);
					this->_nSize += 1;
				}

				void operator>>(T &t) {
					if (_nPointer_NextElements >= this->_nSize)
						_nPointer_NextElements = 0;
					t = Container[_nPointer_NextElements++];
				}

			};
		}
	}
}
