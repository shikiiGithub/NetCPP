#pragma  once
#include "String.h"
#include <Windows.h>

 class XForm :public Object
 {
 private:
	 HWND hwnd ;
	 int nMaxBuffer ;
	 String strText ;
	 int nWindowID ;
	 void Init()
	 {
#ifndef ANSI
		 TypeName = L"XForm";
#else
		 TypeName = "XForm" ;
#endif
		 nMaxBuffer = 512 ;
		 X = Y = Width = Height = -1 ;
		 nWindowID = -1 ;
	 }
 public:
	 XForm()
	 {

	 }
	 

	 virtual const PtrSTR ToString()
	 {
		 return strText.ToString() ;
	 }

	 virtual void Dispose()
	 {
		 
	 }

 public:
	 	 int X,Y,Width,Height ;
	 void GetRect()
		 {
			 LPRECT pRect ;
			 GetWindowRect(hwnd,pRect) ;
			 X = pRect->left ;
			 Y = pRect->top ;
			 Width = pRect->right-pRect->left ;
			 Height = pRect->bottom-pRect->top ;
		 }
	 void Show(int nGapTime =600)
	 {
		 ::ShowWindow(hwnd,SW_NORMAL) ;
		 Sleep(nGapTime) ;
	 }
	 void SetBufferSize(int nSize)
	 {
		 this->nMaxBuffer = nSize ;
	 }
	void FindWindow( LPCSTR lpClassName,  LPCSTR lpWindowName)
	{
		hwnd = ::FindWindow(lpClassName,lpWindowName) ;
	}
	void SetHandle(HWND hwndx)
	{
		hwnd = hwndx ;
	}
	int GetWindowID()
	{
		this-> nWindowID= ::GetDlgCtrlID(hwnd) ;
		return nWindowID ;
	}
	HWND GetHandle()
	{
		return hwnd ;
	}
	String & Text()
	{
		 strText.Clear() ;
	   _Char * pz = new _Char[nMaxBuffer] ;
#ifndef ANSI 
	   GetWindowTextW(hwnd,pz,nMaxBuffer) ;
#else
	   GetWindowTextA(hwnd,pz,nMaxBuffer) ;
#endif
	  strText = pz ;
	  delete pz ;
	  return strText ;
	}
	static void MoveCursor(int nX,int nY)
	{
		::SetCursorPos(nX,nY) ;
	}
	static void EmulateClick(int nGapTime=600)
	{
		Sleep(nGapTime) ;
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP,0, 0, 0, 0) ;
	}
	void Text(CPtrSTR txt)
	{
#ifndef ANSI 
		SetWindowTextW(hwnd,txt) ;
#else
		GetWindowTextA(hwnd,txt) ;
#endif 
	}
  
 };