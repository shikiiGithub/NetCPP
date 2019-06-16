#pragma  once 
#include "FileStream.h"
namespace System
{
	namespace IO
	{
		class BinaryWriter:public FileStream 
		{
		public:
			BinaryWriter()
			{
#ifndef ANSI
				this->FileStreamKind =L"BinaryWriter";
#else
				this->FileStreamKind = "BinaryWriter" ;
#endif
			}
			bool Open(CPtrSTR FileName)
			{
				return FileStream::Open(FileName,std::ios::binary|std::ios::app) ;
			}

			virtual void ResetFilePointer(int nOffset,std::ios_base::seekdir nRelative=std::ios_base::beg)
			{
				this->pFileStream.seekp(nOffset,nRelative) ;
			}

		protected:
		private:
		};
	}
}