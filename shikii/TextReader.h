#pragma once 
#include "FileStream.h"
#include "StringArray.h"
namespace System
{
	namespace IO
	{


		class TextReader: public FileStream
		{
		private:
			TString __innerText ;
			
		public:

			TextReader()
			{

#ifndef ANSI
				this->FileStreamKind =L"TextReader";
#else
				this->FileStreamKind = "TextReader" ;
#endif
			}
			virtual bool Open(CPtrSTR FileName )
			{
				return FileStream::Open(FileName,std::ios_base::in);
			}
			virtual void ResetFilePointer(int nOffset,std::ios_base::seekdir nRelative= std::ios_base::beg)
			{
				pFileStream.seekg(nOffset,nRelative) ;
			}
			CPtrSTR ReadLine()
			{
				__innerText.clear() ;
				pFileStream>>__innerText ;
				return __innerText.c_str() ;
			}
			CPtrSTR ReadAllText()
			{
				__innerText.clear() ;
				this->ResetFilePointer(0) ;
				_Char ch ;
				while(!pFileStream.eof())
				{
					pFileStream>>ch ;
					 __innerText.push_back(ch) ;
				}
				return __innerText.c_str() ;
			}
		     
			const System::Collections::Generic::StringArray& ReadAllLines()
			{
				System::Collections::Generic::StringArray * strArr = new System::Collections::Generic::StringArray() ;
				while(!pFileStream.eof())
				{
					__innerText.clear() ;
					pFileStream>>__innerText ;
					strArr->AddItem(__innerText.c_str()
						) ;
				}
				return *strArr ;
			}

		protected:
		private:
		};
	}
}