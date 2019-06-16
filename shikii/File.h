#pragma once 
#include "Object.h"
namespace System {
	namespace IO {
		class File {
		public:
			/* File()
            {
            #ifndef ANSI
            this->TypeName = L"File";
            #else
            this->TypeName ="File";
            #endif

            }*/
			static void DeleteFile(CPtrSTR FileName) {
				if (Exists(FileName))
					REMOVE(FileName);
			}

			static bool Exists(CPtrSTR FileName) {

				int n = ACCESS(FileName, 0);
				if (n != -1)
					return true;
				else
					return false;
			}

			static bool Rename(CPtrSTR oldName, CPtrSTR newName) {
				if (RENAME(oldName, newName) == 0)
					return true;
				else
					return false;
			}

			static bool Move(CPtrSTR oldName, CPtrSTR newName) {
				return Rename(oldName, newName);
			}
		};
	}
}