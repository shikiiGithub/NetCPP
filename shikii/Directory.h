#pragma once 
#include "Object.h"
#include  "String.h"
#include  "StringArray.h"
namespace System {
	namespace IO {
		class Directory : public Object {
		public:
			System::Collections::Generic::StringArray arrStr;

			static bool Delete(String &strDir) {
				if (0 == DELETEDIR(strDir.ToString()))
					return true;
				else
					return false;
			}

			static bool CreateDirectory(String &strDir) {
				if (0 == NEWDIR(strDir.ToString())) {
					return true;
				} else {
					return false;
				}
			}

			System::Collections::Generic::StringArray &GetFiles(CPtrSTR path, bool isDeepMode = false) {
				arrStr.Clear();

#ifndef ANSI
#define   SEARCH_DOUBLE_BACKSLASH_STAR  L"\\*"
#define   DOT L"."
#define   DOUBLE_DOT L".."
#define  SEARCH_DOUBLE_BACKSLASH  L"\\"
#else
#define    SEARCH_DOUBLE_BACKSLASH_STAR   "\\*"
#define     DOT "."
#define  SEARCH_DOUBLE_BACKSLASH  "\\"
#define   DOUBLE_DOT ".."
#endif
				//�ļ����
				long hFile = 0;
				//�ļ���Ϣ
				struct FIND_DATA fileinfo;
				TString p;
				if ((hFile = FIND_FIRST(p.assign(path).append(SEARCH_DOUBLE_BACKSLASH_STAR).c_str(), &fileinfo)) !=
					-1) {
					do {
						//�����Ŀ¼,����֮
						//�������,�����б�
						if ((fileinfo.attrib & _A_SUBDIR) && isDeepMode) {
							if (STRCMP(fileinfo.name, DOT) != 0 && STRCMP(fileinfo.name, DOUBLE_DOT) != 0) {
								p.assign(path).append(SEARCH_DOUBLE_BACKSLASH).append(fileinfo.name);
								GetFiles(p.c_str());
							}
						} else {
							arrStr << (p.assign(path).append(SEARCH_DOUBLE_BACKSLASH).append(fileinfo.name).c_str());
						}
					} while (FINDE_NEXT(hFile, &fileinfo) == 0);
					FIND_CLOSE(hFile);
					return arrStr;
				}
			}

			System::Collections::Generic::StringArray &GetDirectories(CPtrSTR path) {
				arrStr.Clear();

#ifndef ANSI
#define   SEARCH_DOUBLE_BACKSLASH_STAR  L"\\*"  
#define   DOT L"."
#define   DOUBLE_DOT L".."
#define  SEARCH_DOUBLE_BACKSLASH  L"\\"
#else
#define    SEARCH_DOUBLE_BACKSLASH_STAR   "\\*"
#define     DOT "."
#define  SEARCH_DOUBLE_BACKSLASH  "\\"
#define   DOUBLE_DOT ".."
#endif
				//�ļ����
				long hFile = 0;
				//�ļ���Ϣ
				struct FIND_DATA fileinfo;
				TString p;
				if ((hFile = FIND_FIRST(p.assign(path).append(SEARCH_DOUBLE_BACKSLASH_STAR).c_str(), &fileinfo)) !=
					-1) {
					do {
						//�����Ŀ¼,����֮
						//�������,�����б�
						if ((fileinfo.attrib & _A_SUBDIR)) {
							p.assign(path).append(SEARCH_DOUBLE_BACKSLASH).append(fileinfo.name);
							arrStr << p.c_str();
						}

					} while (FINDE_NEXT(hFile, &fileinfo) == 0);
					FIND_CLOSE(hFile);
					return arrStr;
				}
			}

			static bool Exists(CPtrSTR DirectoryPath) {

				int n = ACCESS(DirectoryPath, 0);
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

		};
	}
}