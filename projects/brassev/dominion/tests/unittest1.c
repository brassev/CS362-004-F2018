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

	// Test the initialize game function:
	int kingdomCards[10] = {
		 adventurer, 
		 gardens, 
		 embargo, 
		 village, 
		 minion, 
		 mine, 
		 cutpurse, 
		 sea_hag, 
		 tribute, 
		 smithy
	};
	assert(initializeGame(2, kingdomCards, 1, &state) == 0, "Returned -1 for nominal case");
	assert(state.supplyCount[curse] == 10, "Returned invalid # of curse cards for the number of players");
	
	assert(7 == fullDeckCount(0, copper, &state), "Player 0 didn't start with the right amount of copper"); // Test initial hand copper
	assert(7 == fullDeckCount(1, copper, &state), "Player 1 didn't start with the right amount of copper");
	
	memset(&state, 0, sizeof(struct gameState));

	assert(initializeGame(1, kingdomCards, 1, &state) == -1, "Returned 0 for too few players");
	assert(initializeGame(MAX_PLAYERS + 1, kingdomCards, 1, &state) == -1, "Returned 0 for too many players");
	int kingdomCards_Repeated[10] = {
		 smithy,
		 smithy,
		 smithy,
		 smithy,
		 smithy,
		 smithy,
		 smithy,
		 smithy,
		 smithy,
		 smithy
	};
	assert(initializeGame(2, kingdomCards_Repeated, 1, &state) == -1, "Returned 0 for repeated kingdom cards");

	printf("%s\n", "Finished with Unit Test 1...");
}