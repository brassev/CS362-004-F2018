#include "../dominion.h"
#include <stdio.h>
#include <memory.h>

int compare(const void*, const void*);

void assert(char test, char* message) {
	if (!test) {
		printf("%s\n", message);
	}
}

int main() {
	int A = 5;
	int B = 7;
	assert(compare((void*)&A, (void*)&B) == -1, "Compare handled B greater than A wrong");
	assert(A == 5 && B == 7, "Compare modified A or B");
	B = 3;
	assert(compare((void*)&A, (void*)&B) == 1, "Compare handled B less than A wrong");
	assert(A == 5 && B == 3, "Compare modified A or B");
	A = 3;
	assert(compare((void*)&A, (void*)&B) == 0, "Compare handled B equals A wrong");
	assert(A == 3 && B == 3, "Compare modified A or B");

	printf("Unit Test 3: Finished\n");
}
/*
int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b)
		return 1;
	if (*(int*)a < *(int*)b)
		return -1;
	return 0;
}
*/