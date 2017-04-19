/* graph01.c
 * main function - read in inputfile and build a graph in C 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
		// printf("element in line is %i\n", sscanfRetn);
		printf("values: a=%i, b=%i\n", a, b);
		// printf("%s\n", line);
			printf("a = %i\n", a);

		IntVec newVec;
		if (array[a] != NULL) {
			newVec = array[a];
		} else {
			newVec = intMakeEmptyVec();
		}

		if (sscanfRetn == 2) {
			weight = 0.0;
			// printf("values: a=%i, b=%i\n", a, b);
			intVecPush(newVec, b);
			array[a] = newVec;

			// printf("\nsize of newVec: %d\n", intSize(newVec));
			// printf("capacity of newVec: %d\n", intCapacity(newVec));
		} else if (sscanfRetn == 3) {
			// printf("values: a=%i, b=%i, weight=%f\n", a, b, weight);
			intVecPush(newVec, b);
			array[a] = newVec;

			// printf("\nsize of newVec: %d\n", intSize(newVec));
			// printf("capacity of newVec: %d\n", intCapacity(newVec));
		}
	}

	// printf("%i\n", intData(array[6], 0));
	// printf("%i\n", intData(array[6], 1));
	// printf("%i\n", intData(array[6], 2));
	// printf("%i\n", intData(array[6], 3));
	for (int i=1; i<arraySize; i++) {
		printf("%i     [", i);
		for (int j=0; j<intSize(array[i]); j++) {
			if (j>0)
				printf(",");
			printf("%i", intData(array[i], j));
		}
		printf("]\n");
	}
	
	return 0;
}