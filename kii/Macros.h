
#pragma once 
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <io.h>
#include <stdlib.h>
#include <direct.h>
#define Char  wchar_t
#define CharSequencePointer  wchar_t*

#define TBaseFileStream std::wfstream
#define TStringStream std::wstringstream
 #define STRCMP       wcscmp
#define SPRINTF swprintf 

 #define  uchar   unsigned wchar_t
#define  ACCESS  _waccess
#define  REMOVE  _wremove
#define  STRLEN  wcslen
#define  NEWDIR   _wmkdir
#define  DELETEDIR _wrmdir
#define  FIND_FIRST _wfindfirst
#define  FINDE_NEXT _wfindnext
#define  FIND_DATA   _wfinddata_t
#define  FIND_CLOSE  _findclose
#define  RENAME  _wrename
#define  VSNPRINTF _vsnwprintf
#define   StrToInt  _wtoi
#define  StrToDouble _wtof
#define StrToLong   _wtol

#define  BACK_SLASH    L"\\" 
#define DOT           L"."

typedef  unsigned char  byte;
 