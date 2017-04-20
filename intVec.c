/* intVec.c
 * define methods for intVec
 * Lynne Okada
 * lyokada@ucsc.edu
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

	return myVec->data[myVec->sz-1];
}

int intData(IntVec myVec, int i) {
	if (i < 0 || i >= myVec->sz) {
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
	IntVec newVec = calloc(1,sizeof(struct IntVecNode));
	int *array = calloc(intInitCap, sizeof(int));
	newVec->data = array;
	newVec->sz = 0;
	newVec->capacity = intInitCap;
	return newVec;
}

void intVecPush(IntVec myVec, int newE) {
	if (myVec == NULL) {
		perror("error: IntVec has not been constructed.");
		return;
	}

	printf("newE = %i\n", newE);
	if (myVec->capacity == myVec->sz) {
		int newCap = 2*myVec->capacity;
		int *newData = realloc(myVec->data, newCap*sizeof(int));

		if (newData != myVec->data) {
			myVec->data = newData;
		}
		myVec->capacity = newCap;
	}
	int i = 0;
	while (myVec->data[i] != 0) {
		i++;
	}
	myVec->data[i] = newE;
	myVec->sz += 1;
	return;
}

void intVecPop(IntVec myVec) {
	if (myVec == NULL) {
		perror("error: IntVec has not been constructed.");
		return;
	} else if (intSize(myVec)<=0) {
		perror("error: IntVec is empty.");
		return;
	}

	if (intCapacity(myVec) > intInitCap && myVec->sz == myVec->capacity/2) {
		int newCap = myVec->capacity/2;
		int *newData = realloc(myVec->data, newCap*sizeof(int));
		if (newData != myVec->data) {
			myVec->data = newData;
		}
		myVec->data = newData;
	}
	myVec->sz = intSize(myVec)-1;

	return;
}