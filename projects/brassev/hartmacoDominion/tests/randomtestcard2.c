#include "common.h"

const int testCard = council_room;

//void cardEffect_council_room(struct gameState *state, int currentPlayer, int handPos);
int councilRoomEffect(int const currentPlayer, struct gameState* state, int const handPos);
/*
void cardEffect_council_room(struct gameState *state, int currentPlayer, int handPos) {
	//+4 Cards
	for (int i = 0; i < 4; i++)
	{
		drawCard(currentPlayer, state);
	}

	//+1 Buy
	state->numBuys++;

	//Each other player draws a card
	for (int i = 0; i < state->numPlayers; i++)
	{
		if (i != currentPlayer)
		{
			drawCard(i, state);
		}
	}

	//put played card in played card pile
	discardCard(handPos, currentPlayer, state, 0);
}
*/

void oracle(struct gameState * state, int currentPlayer, int handPos) {
	// Everybody draws a card
	for (int player = 0; player < state->numPlayers; ++player){
		state->hand[player][state->handCount[player]++] = state->deck[player][--(state->deckCount[player])];
	}
	// The player that played the card draws three more cards
	for (int _ = 0; _ < 3; ++_){
		state->hand[currentPlayer][state->handCount[currentPlayer]++] = state->deck[currentPlayer][--(state->deckCount[currentPlayer])];
	}
	// Give the player more buys
	state->numBuys++;

	// Put the council_room card into the played cards
	state->playedCards[state->playedCardCount++] = state->hand[currentPlayer][handPos];

	// Discard the council room card
	state->hand[currentPlayer][handPos] = state->hand[currentPlayer][--(state->handCount[currentPlayer])];
	state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
}

void run_test(struct gameState * oracleState, struct gameState * state) {
	oracle(oracleState, oracleState->whoseTurn, handPos);
	//cardEffect_council_room(state, state->whoseTurn, handPos);
	councilRoomEffect(state->whoseTurn, state, handPos);
}
