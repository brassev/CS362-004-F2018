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
	state.hand[0][0] = smithy;
	state.deckCount[0] = 3;
	state.deck[0][0] = copper;
	state.deck[0][1] = copper;
	state.deck[0][2] = copper;
	state.discardCount[0] = 0;
	int playerHandSize = state.handCount[0];

	cardEffect(smithy, 0, 0, 0, &state, 0, 0);

	assert(state.handCount[0] == playerHandSize + 2, "Didn't draw 3 cards or didn't discard smithy card");
	assert(state.playedCardCount == 1, "Smithy card not discarded.");

	printf("%s\n", "Card Test 1: Finished");
}