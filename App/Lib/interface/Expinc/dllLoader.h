#ifndef _DLL_LOADER_
#define _DLL_LOADER_

#include <windows.h>
#include <winbase.h>
#include <windef.h>

#define OK 0
#define GENERIC_ERROR -1

typedef int (*compFunc)(int, int);

typedef struct{
        compFunc equal;
        compFunc great;
        compFunc less;
}compFunctions;

int loadDll(void);

int closeDll(void);

void setDllDirectory(char*);

int getDllFunctions(void);

#endif
