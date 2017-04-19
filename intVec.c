/* intVec.c
 * define methods for intVec
 */

 #include "intVec.h"

 struct IntVecNode {
 	int * data;
 	int sz;
 	int capacity;
 };

int intTop(IntVec myVec) {
	if (myVec == NULL) {
		perror("error: IntVec has not been constructed.");
		return 0;
	} else if (myVec->data == NULL) {
		perror("error: IntVec data is empty");
		return 0;
	}
	int n=1;
	int top = myVec->data[myVec->sz-n];
	while (top == NULL) {
		n++;
		top = myVec->data[myVec->sz-n];
	}
	return top;
}

int intData(IntVec myVec, int i) {
	if (i < 0 || i > intSize(myVec)) {
		perror("error: index is out of range.");
		return 0;
	}
	return myVec->data[i];
}

int intSize(IntVec myVec) {
	if (myVec == NULL) {
		perror("error: IntVec has not been constructed");
	}
	return myVec->sz;
}

int intCapacity(IntVec myVec) {
	if (myVec == NULL) {
		perror("error: IntVec has not been constructed");
	}
	return myVec->capacity;
}

IntVec intMakeEmptyVec(void) {
	printf("empty intVec created\n");
	IntVec newVec = calloc(1,sizeof(struct IntVecNode));
	int *array = calloc(1, sizeof(int));
	newVec->data = array;
	newVec->sz = 0;
	newVec->capacity = intInitCap;
	// newVec->capacity = calloc(intInitCap, sizeof(int));
	return newVec;
}

void intVecPush(IntVec myVec, int newE) {
	if (myVec == NULL) {
		perror("error: IntVec has not been constructed.");
		return;
	}

	if (intCapacity(myVec) == intSize(myVec)) {
		// double array
	} else {
		myVec->sz = intSize(myVec)+1;
		int i = 0;
		while (myVec->data[i] != NULL) {
			i++;
		}
		myVec->data[i] = newE;
	}
	
	return;
}

void intVecPop(IntVec myVec) {

}