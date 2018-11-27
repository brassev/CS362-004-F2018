#include "common.h"

const int testCard = smithy;

void cardEffect_smithy(struct gameState* state, int currentPlayer, int handPos);
/*
void cardEffect_smithy(struct gameState* state, int currentPlayer, int handPos) {
	//+3 Cards
	for (int i = 0; i < 3; i++)
	{
		drawCard(handPos, state);
	}

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
}
*/

void oracle(struct gameState * state, int currentPlayer, int handPos) {
	// Draw Three cards
	for (int _ = 0; _ < 3; ++_){
		state->hand[currentPlayer][state->handCount[currentPlayer]++] = state->deck[currentPlayer][--(state->deckCount[currentPlayer])];
	}
	// Put the smithy card into the played cards
	state->playedCards[state->playedCardCount++] = state->hand[currentPlayer][handPos];

	// Discard the smithy card
	state->hand[currentPlayer][handPos] = state->hand[currentPlayer][--(state->handCount[currentPlayer])];
	state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
}

void run_test(struct gameState * oracleState, struct gameState * state) {
	oracle(oracleState, oracleState->whoseTurn, handPos);
	cardEffect_smithy(state, state->whoseTurn, handPos);
}