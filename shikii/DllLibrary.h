#pragma once
#include <windows.h>
class DllLibrary
{
public:
  bool Link(char * pszDllName)
	{
		strcpy(this->pszDllName, pszDllName);
		hInstLibrary = LoadLibrary(pszDllName);
		if (hInstLibrary == NULL)
		{
			FreeLibrary(hInstLibrary);
			return false;
		}
		else
			return true;
	}
/*
	 typedef  HANDLE(*XL_CreateTaskByURL)(const wchar_t *url, const wchar_t *path, const wchar_t *fileName, BOOL IsResume);
	 XL_CreateTaskByURL createTask;
	 bool isCreatedTask = dllManager.LocateFuction(&createTask, "XL_CreateTaskByURL");
*/
  template <typename T>	
  bool LocateFuction
	  (T * pFun,char * pszFunctionName)
	{
		*pFun = (T)GetProcAddress(hInstLibrary, pszFunctionName);
		if (pFun==NULL)
		{
			FreeLibrary(hInstLibrary);
			return false;
		}
		return true;
	}
  bool Disconnect()
  {
	return  FreeLibrary(hInstLibrary);
  }
protected:
	char pszDllName[256];
	HINSTANCE hInstLibrary;
};

 