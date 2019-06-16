#pragma once
#include "Char.h"
#include "StringArray.h"
#include <stdarg.h>
#include<locale>
namespace System {
	class String : public Object {
	private:
		void Init() {
			nNumChsTotal = 128;
			NumChs = new _Char[nNumChsTotal];
#ifndef  ANSI
			this->TypeName =L"String";
#else
			TypeName = "String";
#endif

		}

	public:
		System::Collections::Generic::StringArray SplitedArray;
		TString str;
		int nNumChsTotal;
		_Char *NumChs;

		virtual Object &Invoke(Object *Objs, int n) {
			//CPtrSTR pszMethodName = GetMethodName(Objs[0]) ;

		}

		String() {
			Init();
		}

		String(int n) {
			Init();
#ifndef  ANSI
			SPRINTF(NumChs,L"%d",n) ;
#else
			SPRINTF(NumChs, "%d", n);
#endif
			str = NumChs;
		}

		String(double lf) {
			Init();
#ifndef  ANSI
			SPRINTF(NumChs,L"%lf",lf) ;
#else
			SPRINTF(NumChs, "%lf", lf);
#endif
			str = NumChs;
		}

		String(CPtrSTR str) {
			Init();
			this->str = str;

		}

		String(TString &str) {
			Init();
			this->str = str;
		}

		String &operator=(int n) {
#ifndef  ANSI
			SPRINTF(NumChs,L"%d",n) ;
#else
			SPRINTF(NumChs, "%d", n);
#endif
			str = NumChs;
		}

		String &operator=(double lf) {
#ifndef ANSI
			SPRINTF(NumChs,L"%lf",lf) ;
#else
			SPRINTF(NumChs, "%lf", lf);
#endif
			return *this;
		}

		String &operator=(CPtrSTR str) {
			this->str = str;
			return *this;
		}

		String &operator=(const TString &str) {
			this->str = str;
			return *this;
		}

		String &operator=(const String &str) {
			this->str = str.str;
		}

		virtual bool operator==(Object &obj) {
			if (STRCMP(this->TypeName, obj.TypeName) == 0)
				return this->operator==(obj.ToString());
			else
				return false;
		}

		virtual bool operator==(CPtrSTR str) {
			if (this->str.compare(str) == 0)
				return true;
			else
				return false;
		}

		virtual bool operator==(TString &str) {
			if (this->str.compare(str) == 0)
				return true;
			else
				return false;
		}

		virtual bool operator==(String &str) {
			if (this->str.compare(str.str) == 0)
				return true;
			else
				return false;
		}

		void operator+=(CPtrSTR str) {
			this->str += str;
		}

		void operator+=(TString str) {
			this->str += str;
		}

		void operator+=(String &str) {
			this->str += str.str;
		}

		void operator+=(_Char &ch) {
			str.push_back(ch);
		}

		void operator+=(Char &ch) {
			str.push_back((_Char) ch);
		}

		_Char operator[](int n) {
                 return this->str[n] ;
		}

		operator int()
		{
			return  StrToInt(this->str.c_str());
		}
		operator double()
		{
			return  StrToDouble(this->str.c_str());
		}
		operator float ()
		{
			return  (float)StrToDouble(this->str.c_str());
		}
		operator long()
		{
			return StrToLong(this->str.c_str());
		}
		int Count() {
			return this->str.size();
		}

		String &SubString(int nBeginAt) {
			return SubString(nBeginAt, this->Count() - 1);
		}

		String &SubString(int nBeginAt, int nEndAt) {

			_Char *psChs = new _Char[nEndAt - nBeginAt + 1];
			for (int i = nBeginAt, z = 0; i <= nEndAt; ++i, z++) {
				psChs[z] = this->str[i];
			}
			String *pstr = new String(psChs);
			delete[] psChs;

			return *pstr;
		}

		void Clear() {
			str.clear();
			delete[]  NumChs;
		}

		bool Contains(PtrSTR _str) {
			int n = str.find(_str);
			if (n != -1)
				return true;
			else
				return false;
		}

		bool Contains(TString &_str) {
			int n = str.find(_str);
			if (n != -1)
				return true;
			else
				return false;
		}

		bool Contains(String &_str) {
			int n = str.find(_str.str);
			if (n != -1)
				return true;
			else
				return false;
		}

		int IndexOf(PtrSTR _str) {
			return str.find(_str);
		}

		bool IndexOf(TString &_str) {
			return str.find(_str);
		}

		int IndexOf(String &_str) {
			return str.find(_str.str);
		}

		int LastIndexOf(PtrSTR _str) {
			return str.find_last_of(_str);
		}

		bool LastIndexOf(TString &_str) {
			return str.find_last_of(_str);
		}

		int LastIndexOf(String &_str) {
			return str.find_last_of(_str.str);
		}

		void Insert(int nPos, CPtrSTR pstr) {
			str.insert(nPos, pstr);
		}

		void Insert(int nPos, const TString &pstr) {
			str.insert(nPos, pstr);
		}

		void Insert(int nPos, const String &pstr) {
			str.insert(nPos, pstr.str);
		}

		static bool IsNullorEmptyorSpace(CPtrSTR pstr) {
			if (pstr == NULL)
				return true;
			if (STRLEN(pstr) == 0)
				return true;
#ifndef ANSI

            if(STRLEN(pstr)==1)
            {
                if(pstr[0]==L' ')
                    return true ;
            }

#else

			if (STRLEN(pstr) == 1) {
				if (pstr[0] == ' ')
					return true;
			}


#endif
			return false;

		}

		System::Collections::Generic::StringArray &Split(const TString &seperator) {
			return Split(seperator.c_str());
		}

		System::Collections::Generic::StringArray &Split(CPtrSTR seperator) {
			SplitedArray.Clear();
			typedef int string_size;
			string_size i = 0;
			int nCount = str.size();
			int seperator_Count = STRLEN(seperator);
			while (i != nCount) {
				//找到字符串中首个不等于分隔符的字母；
				int flag = 0;
				while (i != nCount && flag == 0) {
					flag = 1;
					for (string_size x = 0; x < seperator_Count; ++x)
						if (str[i] == seperator[x]) {
							++i;
							flag = 0;
							break;
						}
				}

				//找到又一个分隔符，将两个分隔符之间的字符串取出；
				flag = 0;
				string_size j = i;
				while (j != nCount && flag == 0) {
					for (string_size x = 0; x < seperator_Count; ++x)
						if (str[j] == seperator[x]) {
							flag = 1;
							break;
						}
					if (flag == 0)
						++j;
				}
				if (i != j) {
					SplitedArray << (str.substr(i, j - i)).c_str();
					i = j;
				}
			}
			return SplitedArray;
		}

		System::Collections::Generic::StringArray &Split(String &seperator) {
			return Split(seperator.str.c_str());
		}

		String &Trim() {
			if (String::IsNullorEmptyorSpace(this->ToString())) {
				return *this;
			}
			String *xstr = new String(*this);
#ifndef ANSI
			xstr->str.erase(0,xstr->str.find_first_not_of(L" "));
#else
			xstr->str.erase(xstr->str.find_last_not_of(" ") + 1);
#endif
			return *xstr;
		}

		CPtrSTR ToUpper() {
			int n = str.size();
			_Char *arr = new _Char[n];

			for (int i = 0; i < n; i++) {
				arr[i] = toupper(str[i]);
			}
			return arr;
		}

		CPtrSTR ToLower() {
			int n = str.size();
			_Char *arr = new _Char[n];

			for (int i = 0; i < n; i++) {
				arr[i] = tolower(str[i]);
			}
			return arr;
		}

		//Replace_all_distinct
		String &Replace(const TString &old_value, const TString &new_value) {
			TString pstr = str;
			int nNewValueSize = new_value.length();
			for (int pos = 0; pos != TString::npos; pos += nNewValueSize) {
				if ((pos = pstr.find(old_value, pos)) != TString::npos) {
					pstr.replace(pos, old_value.length(), new_value);
				} else { break; }
			}
			return *(new String(pstr));
		}

		static String &Format(CPtrSTR format, ...) {
#define FORMAT_MSG_BUFFER_SIZE 204800
			_Char *szBuffer = new _Char[FORMAT_MSG_BUFFER_SIZE + 1];
			va_list args;
			va_start(args, format);
			VSNPRINTF(szBuffer, FORMAT_MSG_BUFFER_SIZE, format, args);
			va_end(args);
			String *_xstr = new String(szBuffer);
			delete[] szBuffer;
			return *_xstr;
		}

		// 出错时返回字符中全为‘\n’
		static const char * ToANSIString(const wchar_t * unicodeStr)

		{
			std::string _str;
			std::locale loc = std::locale("zh-CN");
			int n = wcslen(unicodeStr) ;
			for (int i = 0 ;i< n; i++)
			{
				char ch = std::use_facet<std::ctype<char >>(loc).narrow(unicodeStr[i],'\n') ;
				_str.push_back(ch);
			}

			return _str.c_str();
		}
		static const wchar_t  * ToUnicodeString(const char * ansiStr)
		{
			std::wstring wstr;
			std::locale loc = std::locale();
			int n =  strlen(ansiStr) ;
			for (int i = 0 ;i< n; i++)
			{
				wchar_t wchar = std::use_facet<std::ctype<wchar_t>>(loc).widen(ansiStr[i]);
				wstr.push_back(wchar);
			}

			return wstr.c_str();
		}
		static std::wstring& ToUnicodeString(std::string& _str)
		{
			std::wstring wstr;
			std::locale loc = std::locale();
			int n = _str.length() ;
			for (int i = 0 ;i< n; i++)
			{
				wchar_t wchar = std::use_facet<std::ctype<wchar_t>>(loc).widen(_str[i]);
				wstr.push_back(wchar);
			}

			return wstr;
		}

		static std::string& ToANSIString(std::wstring wstr)
		{

		   std::string _str;
			std::locale loc = std::locale();
			int n = wstr.length() ;
			for (int i = 0 ;i< n; i++)
			{
				char ch = std::use_facet<std::ctype<wchar_t>>(loc).narrow(wstr[i],'\n') ;
				_str.push_back(ch);
			}

			return _str;
		}
		virtual const PtrSTR ToString() {
			return str.c_str();
		}

		virtual void Dispose() {
			Clear();
		}

	private:
		int tolower(int c) {
			if ((c >= 'A') && (c <= 'Z'))
				return c + ('a' - 'A');
			return c;
		}

		int toupper(int c) {
			if ((c >= 'a') && (c <= 'z'))
				return c + ('A' - 'a');
			return c;
		}

	};
    #define  RefString String&
    typedef RefString string ;
}
/*
StringArray& Split(CPtrSTR pstr)
{
int n = STRLEN(pstr) ;
_Char ch = pstr[0] ;
TString * segment = new TString() ;
int nCount = str.size() ;
for (int i=0;i< nCount ;i++)
{

if(pstr[i]==ch)
{
for (int j=1;j< n-1 ;j++)
{
if( pstr[i+j]== pstr[j] )
{

}
else
break; 
}
}

}
}
*/
