/* graph01.c
 * main function - read in inputfile and build a graph in C 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intVec.h"

int main(int argc, char* argv[]) 
{
	FILE *inputfile = fopen(argv[1], "r");

	if (!inputfile) {
		printf("error: no inputfile found");
		return 1;
	}
	printf("Opened %s for inputs.\n", argv[1]);
	char line[1024];
	fgets(line, 1024, inputfile);
	int arraySize = atoi(line);
	IntVec array[arraySize];
	
	while (fgets(line, 1024, inputfile) != NULL) {
		int a, b;
		double weight;
		int sscanfRetn = sscanf(line, " %i %i %lf", &a,&b,&weight);
		printf("element in line is %i\n", sscanfRetn);
		printf("%s\n", line);
		
		if (sscanfRetn == 2) {

		} else if (sscanfRetn == 3) {

		}

	}

	// IntVec array[arraySize];

	for (int i=0; i < arraySize; i++) {
		printf("%i", i);
	}

	return 0;
}