#pragma  once 
#include "Object.h"
namespace System
{
	namespace IO
	{
		class FileStream :public Object
		{
		public:
			PtrSTR FileName ;
			PtrSTR FileStreamKind ;
			TBaseFileStream  pFileStream ;

			FileStream()
			{
#ifndef ANSI
				this->TypeName =L"FileStream";

#else
				this->TypeName = "FileStream" ;
#endif
#ifndef ANSI
				std::locale lang("chs") ;
				pFileStream.imbue( lang) ;
#endif
			}


			/*
			0 --Begine
			1 --Current
			2 --End
			*/
			virtual void ResetFilePointer(int nOffset,int nRelative=0) =0 ;

			void Write(byte * byts,int nCount)
			{
				pFileStream.write((PtrSTR)byts,nCount) ;     
			}
			void Read(byte * byts,int nCount)
			{
				pFileStream.read((PtrSTR)byts,nCount) ;
			}
			void Close()
			{
				pFileStream.close() ;

			}

			virtual const PtrSTR ToString()
			{
				TString str=FileName  ;
#ifndef ANSI
				str += L" " ;
				str += this->TypeName ;
#else
				str+=" ";
				str+=this->TypeName ;
#endif

				return  str.c_str() ;
			}


			virtual bool operator ==(Object& obj)
			{
				if(Object::operator ==(obj))
				{
					FileStream * fs = dynamic_cast<FileStream *>(&obj) ;
					return pFileStream == fs->pFileStream ;
				}

			}
			virtual void Dispose()
			{
				Close() ;
			}
			~FileStream()
			{
				Dispose() ;
			}
		protected:

			bool Open(CPtrSTR FileName,std::ios_base::openmode mode)
			{

				pFileStream.open(FileName,mode) ;

				return pFileStream.is_open() ;
			}

		};

	}
}