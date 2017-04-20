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
	int arraySize = atoi(line)+1;
	IntVec *array = calloc(arraySize, sizeof(IntVec));

	// // make sure the array is empty
	// for (int i=0;i<arraySize;i++) {
	// 	array[i] = NULL;
	// }

	while (fgets(line, 1024, inputfile) != NULL) {
		int a, b;
		double weight;
		int sscanfRetn = sscanf(line, " %i %i %lf", &a,&b,&weight);

		IntVec newVec;
		if (array[a] == NULL) {
			newVec = intMakeEmptyVec();
		} else {
			newVec = array[a];
		}

		printf("pushing element %i to index %i\n", b, a);
		if (sscanfRetn == 2) {
			weight = 0.0;
			intVecPush(newVec, b);
			array[a] = newVec;
		} else if (sscanfRetn == 3) {
			intVecPush(newVec, b);
			array[a] = newVec;
		}
	}

	for (int i=0; i<arraySize; i++) {
		if (i==0) 
			printf("%i\n", arraySize-1);
		else if (array[i]==NULL) {
			printf("%i     [", i);
			printf("NULL]\n");
		} else {
			printf("%i     [", i);	
			// printf("intSize(array[i]) %i\n", intSize(array[i]));
			for (int j=0; j<intSize(array[i]); j++) {
				if (j>0)
					printf(",");
				printf("%i", intData(array[i], j));
			}
		printf("]\n");
		}
	}
	
	return 0;
}