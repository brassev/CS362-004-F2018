#include "../dominion.h"
#include <stdio.h>
#include <memory.h>

int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

void assert(char test, char* message) {
	if (!test) {
		printf("%s\n", message);
	}
}

int main() {

	struct gameState state = { 0 };

	// Test the initialize game function:
	state.handCount[0] = 1;
	state.hand[0][0] = adventurer;
	state.deckCount[0] = 3;
	state.deck[0][0] = gold;
	state.deck[0][1] = copper;
	state.deck[0][2] = gardens;
	state.discardCount[0] = 0;

	cardEffect(adventurer, 0, 0, 0, &state, 0, 0);

	assert(state.handCount[0] == 2, "Didn't find treasure or didn't discard adventurer card");
	assert(state.deckCount[0] == 0, "Didn't search all of the deck");

	printf("%s\n", "Card Test 2: Finished");
}