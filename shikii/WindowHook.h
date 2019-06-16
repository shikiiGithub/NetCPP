#pragma  once
#include "Object.h"
#include <Windows.h>
extern HHOOK Class_Internal_Use_hHook =NULL ; 
extern void * Class_Internal_Use_Ptr_WindowHook = NULL ;
LRESULT CALLBACK MyHookProc
	(
	int nCode,
	WPARAM wParam,
	LPARAM lParam
	) ;
class WindowHook : public Object
{
private:
	void Init()
	{
#ifndef ANSI
		this->TypeName = L"WindowHook";
#else
		this->TypeName = L"WindowHook";
#endif
	 Class_Internal_Use_Ptr_WindowHook = this ;
	}
	bool Inject(int nWhichKindHook,HINSTANCE hInstance,DWORD dwThreadId)
	{
		Class_Internal_Use_hHook = SetWindowsHookEx(nWhichKindHook,MyHookProc,hInstance,dwThreadId) ;
		if(Class_Internal_Use_hHook==NULL)
			return false ;
		else
			return true ;
	}
public:
	WindowHook()
	 {
		 Init() ;
		 
	 }
	bool InJect_CurrentThread(int nWhichKindHook)
	 {
		return Inject(nWhichKindHook,NULL,GetCurrentThreadId()) ;
	 }
	bool InJect_Global(int nWhichKindHook,HINSTANCE dllHandle)
	{
		return Inject(nWhichKindHook,dllHandle,0) ;
	}
	bool UnInject()
	{
		return UnhookWindowsHookEx(Class_Internal_Use_hHook) ;
	}
	virtual const PtrSTR ToString()
	 {
		return TypeName ;
	 }
	virtual void Dispose()
	 {
		 
	 }
	virtual void UserDefineHookProc(int nCode,WPARAM wParam,LPARAM lParam)=0 ;

};

 
LRESULT CALLBACK MyHookProc
	(
	int nCode,
	WPARAM wParam,
	LPARAM lParam
	){
		WindowHook * ptrWindowHook = (WindowHook * )Class_Internal_Use_Ptr_WindowHook ;
		ptrWindowHook->UserDefineHookProc(nCode,wParam,lParam) ;
		return CallNextHookEx(Class_Internal_Use_hHook, nCode, wParam, lParam); 
}