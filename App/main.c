#include <stdio.h>
#include "compare.h"
#include "dllLoader.h"

int main(void){

	int err = 0;

	setDllDirectory("Lib/dll/");

	if(!equal(1,1)){
	        if(equal(1,2))
		        printf("equal Dll function works!\n");
	}

	return 0;

}
