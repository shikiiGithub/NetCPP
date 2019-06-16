#pragma once 
#include "Macros.h"
namespace  System {
	class Object {
	protected:
		CPtrSTR GetMethodName(Object * objs) {
			  Object & obj = objs[0] ;
			return obj.ToString();
		}
	public:
		PtrSTR TypeName;
		virtual const PtrSTR ToString()=0;
		//vector<Object> Parms ;

		//virtual Type GetType()=0 ;
		// virtual void CallEngine(CPtrSTR MethodName)=0 ;
		virtual Object &Invoke(Object *Objs, int n) =0;

		virtual bool operator==(Object &obj) {

			if (STRCMP(TypeName, obj.TypeName) == 0)
				return true;
			else
				return false;
		}

		virtual void Dispose()=0;
	};

	class NullObject : Object {
		virtual Object &Invoke(Object *Objs, int n) {
		}

		virtual void Dispose() {

		}
		virtual const PtrSTR ToString()
		{

		}
	public :
		static NullObject &Null() {
			return *(new NullObject());
		}
	};
}