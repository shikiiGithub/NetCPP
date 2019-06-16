#pragma  once 
#include "FileStream.h"
namespace System
{
	namespace IO
	{
		class BinaryReader:public FileStream
		{
		public:
			BinaryReader()
			{
#ifndef ANSI
				this->FileStreamKind =L"BinaryReader";
#else
				this->FileStreamKind = "BinaryReader" ;
#endif
			}
			bool Open(CPtrSTR FileName)
			{
				return FileStream::Open(FileName,std::ios::binary|std::ios::in) ;
			}

			virtual void ResetFilePointer(int nOffset,std::ios_base::seekdir nRelative=std::ios_base::beg)
			{
				this->pFileStream.seekg(nOffset,nRelative) ;
			}

		protected:
		private:
		};
	}
}
