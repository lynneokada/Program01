#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
	FILE *inputfile = fopen(argv[1], "w");

	if (!inputfile) {
		printf("Usage: no inputfile found");
		return 1;
	}

	return 0;
}