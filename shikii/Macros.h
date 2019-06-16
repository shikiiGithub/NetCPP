
#pragma once 
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <io.h>
#include <stdlib.h>
#include <direct.h>
#ifndef ANSI
#define _Char  wchar_t 
#define PtrSTR  wchar_t*  
#define TString  std::wstring
#define TBaseFileStream std::wfstream
#define TStringStream std::wstringstream
 #define STRCMP       wcscmp
#define SPRINTF swprintf 
#define  CPtrSTR  const wchar_t*
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
#else
#define TBaseFileStream std::fstream 
#define _Char char 
#define PtrSTR char*
#define  CPtrSTR  const char*
#define TString std::string
#define SPRINTF sprintf 
#define TStringStream std::stringstream
#define  STRCMP  strcmp
 #define  uchar unsigned char
#define  ACCESS _access
#define  REMOVE remove
#define  STRLEN  strlen
#define  NEWDIR _mkdir
#define  DELETEDIR _rmdir
#define  FIND_FIRST _findfirst
#define  FINDE_NEXT _findnext
#define  FIND_DATA   _finddata_t
#define  FIND_CLOSE  _findclose
#define  RENAME  rename
#define  VSNPRINTF vsnprintf
#define   StrToInt  atoi
#define  StrToDouble atof
#define StrToLong   atol
#endif 
#
#ifndef ANSI
#define  BACK_SLASH    L"\\" 
#define DOT           L"."
#else
#define  BACK_SLASH     "\\"
#define DOT            "."
#endif
typedef  unsigned char  byte;
 