#include "common.h"

const int testCard = adventurer;

//void cardEffect_adventurer(struct gameState *state, int currentPlayer);
int adventurerEffect(int* drawntreasure, struct gameState* state, int const currentPlayer, int cardDrawn,
	int* temphand, int z, int const handPos);
/*
void cardEffect_adventurer(struct gameState *state, int currentPlayer) {
	int drawntreasure = 0;
	int z = 0;
	int temphand[MAX_HAND];// moved above the if statement
	while (drawntreasure < 2) {
		if (state->deckCount[currentPlayer] < 1) {//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		int cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else {
			temphand[z] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while (z >= 0) {
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z]; // discard all cards in play that have been drawn
		z = z - 1;
	}
}
*/

void oracle(struct gameState * state, int currentPlayer) {
	int drawntreasure = 0;

	while (drawntreasure < 2 && state->deckCount[currentPlayer] > 0) {
		state->hand[currentPlayer][state->handCount[currentPlayer]++] = state->deck[currentPlayer][--(state->deckCount[currentPlayer])];
		int drawncard = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];
		if (drawncard == copper || drawncard == silver || drawncard == gold) {
			drawntreasure++;
		} else {
			state->discard[currentPlayer][state->discardCount[currentPlayer]++] = drawncard;
			--state->handCount[currentPlayer];
		}
	}
}

void run_test(struct gameState * oracleState, struct gameState * state) {
	oracle(oracleState, oracleState->whoseTurn);
	int drawntreasure = 0;
	int temphand[MAX_HAND] = { 0 };
	adventurerEffect(&drawntreasure, state, state->whoseTurn, adventurer,
	temphand, 0, handpos);
}