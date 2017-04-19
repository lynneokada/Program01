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

	return myVec->data[myVec->sz-1];
}

int intData(IntVec myVec, int i) {
	// printf("intData called\n");
	if (i < 0 || i >= myVec->sz) {
		perror("intData error: index is out of range.");
		return 0;
	}
	return myVec->data[i];
}

int intSize(IntVec myVec) {
	// printf("intSize called\n");
	if (myVec == NULL) {
		perror("intSize error: IntVec has not been constructed");
	}
	return myVec->sz;
}

int intCapacity(IntVec myVec) {
	// printf("intCapacity called\n");
	if (myVec == NULL) {
		perror("intCapacity error: IntVec has not been constructed");
	}
	return myVec->capacity;
}

IntVec intMakeEmptyVec(void) {
	// printf("empty intVec created\n");
	IntVec newVec = calloc(1,sizeof(struct IntVecNode));
	int *array = calloc(intInitCap, sizeof(int));
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

	// printf("intCapacity(myVec) = %i\n", intCapacity(myVec));
	if (myVec->capacity == myVec->sz) {
		myVec->capacity *= 2;
	} else {
		myVec->sz = intSize(myVec)+1;
		int i = 0;
		while (myVec->data[i] != 0) {
			i++;
		}
		myVec->data[i] = newE;
	}
	
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
		myVec->capacity = intCapacity(myVec)/2;
	}
	myVec->sz = intSize(myVec)-1;

	return;
}