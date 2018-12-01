#include "../dominion.h"
#include <stdio.h>
#include <memory.h>

void assert(char test, char* message) {
	if (!test) {
		printf("%s\n", message);
	}
}

int main() {

	struct gameState state = { 0 };

	// Test the fullDeckCount function:
	int deck[] = { steward, gold, curse, great_hall, copper, duchy, village, village, village, mine, mine, outpost, outpost, outpost, sea_hag };
	int hand[] = { steward, gold, gold, adventurer, curse, copper, smithy };
	int discard[] = { steward, steward, gold, gardens, copper };
	state.deckCount[0] = 15;
	state.handCount[0] = 7;
	state.discardCount[0] = 5;
	memcpy(&state.deck[0], &deck, sizeof(deck) * sizeof(int));
	memcpy(&state.hand[0], &hand, sizeof(hand) * sizeof(int));
	memcpy(&state.discard[0], &discard, sizeof(discard) * sizeof(int));

	assert(fullDeckCount(0, steward, &state) == 4, "Reported incorrect number of steward");
	assert(fullDeckCount(0, gold, &state) == 4, "Reported incorrect number of gold");
	assert(fullDeckCount(0, curse, &state) == 2, "Reported incorrect number of curse");
	assert(fullDeckCount(0, great_hall, &state) == 1, "Reported incorrect number of great_hall");
	assert(fullDeckCount(0, copper, &state) == 3, "Reported incorrect number of copper");
	assert(fullDeckCount(0, duchy, &state) == 1, "Reported incorrect number of duchy");
	assert(fullDeckCount(0, village, &state) == 3, "Reported incorrect number of village");
	assert(fullDeckCount(0, mine, &state) == 2, "Reported incorrect number of mine");
	assert(fullDeckCount(0, outpost, &state) == 3, "Reported incorrect number of outpost");
	assert(fullDeckCount(0, sea_hag, &state) == 1, "Reported incorrect number of sea_hag");
	assert(fullDeckCount(0, adventurer, &state) == 1, "Reported incorrect number of adventurer");
	assert(fullDeckCount(0, smithy, &state) == 1, "Reported incorrect number of smithy");
	assert(fullDeckCount(0, gardens, &state) == 1, "Reported incorrect number of gardens");

	printf("%s\n", "Unit Test 2: Finished");
}