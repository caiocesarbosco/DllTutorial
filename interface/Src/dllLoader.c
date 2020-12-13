#include <stdio.h>
#include "dllLoader.h"
#include "compare.h"
#include <string.h>

HINSTANCE s_dllHandle = NULL;
compFunctions s_dllFcts = {0};
char s_pathToDllDir[200] = {0};

int loadDLL(void) {


	if(s_dllHandle) {
		printf("DLL has been loaded previosly\n");
		return OK;
	}

	strcat(s_pathToDllDir, DLL_NAME);

	s_dllHandle = LoadLibrary(s_pathToDllDir);

	if(s_dllHandle == NULL) {
		printf("DLL Load has been failed: %d\n");
		return GENERIC_ERROR;
		
	}
		
	printf("DLL has been loaded successfully\n");	

	return OK;
}

int closeDLL(void) {

	int err = 0;

	if(s_dllHandle == NULL) {
		printf("DLL has not been loaded previosly\n");
		return GENERIC_ERROR;
	}

	err =  FreeLibrary(s_dllHandle);

	if(err) {
		printf("DLL Close has been failed: %d\n", err);
		return err;
		
	}
	
	printf("DLL has been closed successfully\n");	

	return OK;
}


void setDllDirectory(char *dirPath) {

	memset(s_pathToDllDir, 0, sizeof(s_pathToDllDir));
	strcpy(s_pathToDllDir, dirPath);
	return;
}

int getDllFunction(void) {

	int err = 0;

	if (s_dllHandle == NULL) {
		err = loadDLL();
		if(err)
			return err;
	}

	s_dllFcts.equal = (compFunc) GetProcAddress(s_dllHandle,"equal");
	s_dllFcts.great = (compFunc) GetProcAddress(s_dllHandle,"greaterThan");
	s_dllFcts.less = (compFunc) GetProcAddress(s_dllHandle, "lessThan");
	

	if (s_dllFcts.equal == NULL || s_dllFcts.great == NULL || s_dllFcts.less == NULL) {
		printf("getDllFunction has been failed [%d, %d, %d]\n", s_dllFcts.equal, s_dllFcts.great, s_dllFcts.less);
		return GENERIC_ERROR;
	}

	printf("DLL Functios has been loaded successfully\n");	
	
	return OK;
}

int equal(int numA, int numB) {

	int err = 0;

	if(s_dllFcts.equal == NULL) {
		err = getDllFunction();
		if(err)
			return err;
	}

	return s_dllFcts.equal(numA, numB);

}

int greaterThan(int numA, int numB) {

	int err = 0;

	if(s_dllFcts.great == NULL) {
		err = getDllFunction();
		if(err)
			return err;
	}
	
	return s_dllFcts.great(numA, numB);

}

int lessThan(int numA, int numB) {

	int err = 0;

	if(s_dllFcts.less == NULL) {
		err = getDllFunction();
		if(err)
			return err;
	}
	
	return s_dllFcts.less(numA, numB);

}

