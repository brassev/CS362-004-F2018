#include "../dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

void compareStates(struct gameState * test, struct gameState * expected);
void assert(int current, int expected, char * name);
void fillGameStateRandom(struct gameState * state);
int randInt(int min, int max);

extern const int testCard;
int card;
int choice1;
int choice2;
int choice3;
int handPos;
int *bonus;

void run_test(struct gameState * oracleState, struct gameState * state);
