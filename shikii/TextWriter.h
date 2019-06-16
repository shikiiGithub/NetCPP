#pragma once 
#include "FileStream.h"
namespace System
{
	namespace IO
	{
		class TextWriter :public FileStream
		{
		private:
			TString __innerStr ;
		public:
			TextWriter()
			{
#ifndef ANSI
				this->FileStreamKind =L"TextWriter";
#else
				this->FileStreamKind = "TextWriter" ;
#endif
			}
			virtual bool Open(CPtrSTR _FileName )
			{
				return FileStream::Open(_FileName,std::ios_base::app);
			}

			virtual void ResetFilePointer(int nOffset,std::ios_base::seekdir nRelative= std::ios_base::beg)
			{
				pFileStream.seekp(nOffset,nRelative) ;
			}
			void WriteLine(CPtrSTR str)
			{
				pFileStream<<str<<std::endl ;
			}
			void WriteText(CPtrSTR str)
			{
				__innerStr.clear() ;
				__innerStr = str ;
				int n = __innerStr.size() ;
				for (int i=0;i< n;i++)
				{
					pFileStream<<__innerStr[i];
				}
			}
		};
	}}