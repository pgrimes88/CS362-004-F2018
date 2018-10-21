#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// int cardEffect(int card, int choice1, int choice2, int choice3,
// struct gameState *state, int handPos, int *bonus)
int main(){
    printf("cardtest1.c\n");
    printf("smithy\n");
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    struct gameState game1;
    initializeGame(2, k, 2, &game1);
    //printf("%d\n",whoseTurn(&game1));
    game1.hand[0][0] = smithy;
    struct gameState gameOld;
    gameOld = game1;
    
    int bonus = 0;
    cardEffect(smithy, 0, 0, 0, &game1, 0, &bonus);
    
        int test = 0;
    for(int i = 0; i < 27; i++){
        if(game1.supplyCount[i] == gameOld.supplyCount[i]){
            
        }
        else{
            test = 1;
        }
    }
    
    if(test == 0){
        printf("PASS -- No change to victory card pile and kingdom card pile\n");
    }
    else{
        printf("TEST FAILED -- The supplyCount of kingdom / treasure cards were changed\n");
    }
    
    if(game1.handCount[1] == gameOld.handCount[1] && game1.deckCount[1] == gameOld.deckCount[1] && game1.numActions == gameOld.numActions && whoseTurn(&game1) == whoseTurn(&gameOld)){
       printf("PASS -- Other players' states (hand, deck, action and turn remained the same).\n"); 
    }
    else{
        printf("TEST FAILED -- Other players' states changed\n");
    }
    if(game1.handCount[0] == gameOld.handCount[0] + 2){
        printf("PASS -- Player 0 draws 3 cards (but discards smithy)\n");
    }
    else{
        printf("TEST FAILED -- Player did not draw 3 cards\n");
    }
    
    if(game1.deckCount[0] + 3 == gameOld.deckCount[0]){
        printf("PASS -- Current Player's deck is missing 3 cards\n");
    }
    else{
        printf("TEST FAILED -- Players deck did not go down 3 cards\n\n");
    }
    
    
}