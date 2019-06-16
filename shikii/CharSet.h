#pragma once
#pragma once
#include<Windows.h>
#include <tchar.h>
class CharSet
{
public:
	CharSet()
	{
		 
		//std::locale old_loc = std::locale::global(std::locale("zh-CN"));
		//std::locale::global(old_loc);
	}
	const char * Unicode2Ansi(const  wchar_t * widechar)
	{
		char* pANSIChars;
		 
		DWORD sizeMByte = WideCharToMultiByte(CP_OEMCP, 0, widechar, -1, NULL, 0, NULL, FALSE);
		pANSIChars = new char[sizeMByte];
		WideCharToMultiByte(CP_OEMCP, 0, widechar, -1, pANSIChars, sizeMByte, NULL, FALSE);
		return pANSIChars;
	}
	const	wchar_t * Ansi2Unicode(const char * pAnsi)
	{
		wchar_t * pUnicodeChars;
		 
		DWORD dwNum = 0;
		BOOL bRet = FALSE;

		dwNum = MultiByteToWideChar(CP_ACP, 0, pAnsi, -1, 0, 0);
		pUnicodeChars = new wchar_t[dwNum];
		MultiByteToWideChar(CP_ACP, 0, pAnsi, -1, pUnicodeChars, dwNum);
		return pUnicodeChars;
	}

 
	
	

};