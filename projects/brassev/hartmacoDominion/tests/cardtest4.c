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
	state.hand[0][0] = steward;
	state.deckCount[0] = 3;
	state.deck[0][0] = copper;
	state.deck[0][1] = copper;
	state.deck[0][2] = gardens;
	state.discardCount[0] = 0;

	cardEffect(steward, 2, 0, 0, &state, 0, 0);

	assert(state.coins == 2, "Didn't increase coins");
	assert(state.playedCardCount == 1, "Didn't discard steward card - coins");

	state.handCount[0] = 1;
	state.hand[0][0] = steward;
	state.deckCount[0] = 3;
	state.deck[0][0] = copper;
	state.deck[0][1] = copper;
	state.deck[0][2] = gardens;
	state.discardCount[0] = 0;

	cardEffect(steward, 1, 0, 0, &state, 0, 0);

	assert(state.handCount[0] == 2, "Didn't collect two cards or forgot to discard steward card");
	assert(state.playedCardCount == 1, "Didn't discard steward card - cards");



	printf("%s\n", "Card Test 4: Finished");
}