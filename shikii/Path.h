#pragma  once

#include "String.h"
namespace System {
	namespace IO {
		class Path {
		public:

			static RefString GetDirectoryName(String &strPath) {
				String *strNULL = NULL;
				int nIndex = -1;
				nIndex = strPath.LastIndexOf(BACK_SLASH);
				if (nIndex == -1)
					return *strNULL;
				return strPath.SubString(0, nIndex - 1);
			}

			static RefString ChangeExtension(String &path, String &extension) {
				int nIndex = path.LastIndexOf(DOT);
				String *NullString = NULL;
				if (nIndex == -1)
					return *NullString;
				else {
					RefString strX = path.SubString(0, nIndex - 1);
					strX += extension;
					return strX;
				}
			}

			static RefString GetExtension(String &path) {
				int nIndex = path.LastIndexOf(DOT);
				String *NullString = NULL;
				if (nIndex == -1)
					return *NullString;
				else {
					RefString strX = path.SubString(nIndex - 1);
					return strX;
				}
			}

			static RefString GetFileName(String &path) {
				String *strNULL = NULL;
				int nIndex = -1;
				nIndex = path.LastIndexOf(BACK_SLASH);
				if (nIndex == -1)
					return *strNULL;
				return path.SubString(nIndex - 1);
			}

			static RefString GetFileNameWithoutExtension(
					RefString path
			) {
				String *strNULL = NULL;
				int nIndex = -1;
				nIndex = path.LastIndexOf(BACK_SLASH);
				if (nIndex == -1)
					return *strNULL;
				int nIndex_Dot = path.LastIndexOf(DOT);
				if (nIndex_Dot == -1)
					return *strNULL;
				return path.SubString(nIndex, nIndex_Dot);

			}

			static RefString GetPathRoot(RefString path) {
				String *strNULL = NULL;
				int nIndex = -1;
				nIndex = path.IndexOf(BACK_SLASH);
				if (nIndex == -1)
					return *strNULL;
				return path.SubString(0, nIndex);
			}

			static RefString Combine(
					RefString path1,
					RefString path2
			) {
				String *pStr = new String(path1);
				RefString refStr = *pStr;
				refStr += BACK_SLASH;
				refStr += path2;
				return refStr;
			}

			static RefString Combine(
					RefString path1,
					RefString path2,
					RefString path3
			) {
				String *pStr = new String(path1);
				RefString refStr = *pStr;
				refStr += BACK_SLASH;
				refStr += path2;
				refStr += BACK_SLASH;
				refStr += path3;
				return refStr;
			}

			static RefString Combine(RefString path1, RefString path2, RefString path3, RefString path4) {
				String *pStr = new String(path1);
				RefString refStr = *pStr;
				refStr += BACK_SLASH;
				refStr += path2;
				refStr += BACK_SLASH;
				refStr += path3;
				refStr += BACK_SLASH;
				refStr += path4;
				return refStr;
			}

			//��������ΪString ����
			static String& Combine(int nCount, ...) {

				va_list args;
				va_start(args, nCount);
				String _xstr  ; //= va_arg(args, String);
				RefString refXstr = _xstr;
			/*	for (int i = 1; i < nCount - 1; i++) {
					RefString refStr = va_arg(args, String); //��ȡ�ɱ�������Ķ�������Ϊ�ɱ����������
					refXstr += BACK_SLASH;
					refXstr += refStr;
				}
				va_end(args);*/
				return refXstr;
			}

		};
	}
}