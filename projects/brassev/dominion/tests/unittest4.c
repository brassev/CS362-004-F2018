#include "../dominion.h"
#include <stdio.h>
#include <memory.h>

void assert(char test, char* message) {
	if (!test) {
		printf("%s\n", message);
	}
}

int main() {

	int* test1 = kingdomCards(steward,tribute,ambassador,cutpurse,embargo,outpost,salvager,sea_hag,treasure_map, gold);
	assert(test1[0] == steward, "Didn't place steward into the proper location");
	assert(test1[1] == tribute, "Didn't place tribute into the proper location");
	assert(test1[2] == ambassador, "Didn't place ambassador into the proper location");
	assert(test1[3] == cutpurse, "Didn't place cutpurse into the proper location");
	assert(test1[4] == embargo, "Didn't place embargo into the proper location");
	assert(test1[5] == outpost, "Didn't place outpost into the proper location");
	assert(test1[6] == salvager, "Didn't place salvager into the proper location");
	assert(test1[7] == sea_hag, "Didn't place sea_hag into the proper location");
	assert(test1[8] == treasure_map, "Didn't place treasure_map into the proper location");
	assert(test1[9] == gold, "Didn't place gold into the proper location");

	printf("Finished executing unit test 4.");
}
/*
int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7,
	int k8, int k9, int k10) {
	int* k = malloc(10 * sizeof(int));
	k[0] = k1;
	k[1] = k2;
	k[2] = k3;
	k[3] = k4;
	k[4] = k5;
	k[5] = k6;
	k[6] = k7;
	k[7] = k8;
	k[8] = k9;
	k[9] = k10;
	return k;
}
*/