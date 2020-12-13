#include <stdlib.h>
#include "compare.h"

int equal(int numA, int numB){
	return(!(numA == numB));
}

int greaterThan(int numA, int numB){
	return(numA > numB);
}

int lessThan(int numA, int numB){
	return (numA < numB);
}
