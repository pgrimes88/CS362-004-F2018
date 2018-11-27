#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    printf("cardtest4.c\n");
    printf("Sea Hag\n");
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    struct gameState game1;
    initializeGame(2, k, 2, &game1);
    //printf("%d\n",whoseTurn(&game1));
    game1.hand[0][0] = sea_hag;
    struct gameState gameOld;
    gameOld = game1;
    
    int bonus = 0;
    cardEffect(sea_hag, 0, 0, 0, &game1, 0, &bonus);
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
    
    if(game1.handCount[0] == gameOld.handCount[0] && game1.deckCount[0] == gameOld.deckCount[0] && game1.discardCount[0] == gameOld.discardCount[0]  && whoseTurn(&game1) == whoseTurn(&gameOld)){
       printf("PASS -- current players' states (hand, deck, dicard pile and turn remained the same).\n"); 
    }
    else{
        printf("TEST FAILED -- current players' states changed\n");
    }
    if(game1.discardCount[1] - 1  == gameOld.discardCount[1]){
        printf("PASS -- 1 card added to dicard pile by opponent\n");
    }
    else{
        printf("TEST FAILED -- 1 card not added to discard pile\n");
    }
    if(game1.deckCount[1]  == gameOld.deckCount[1]){
        printf("PASS -- deck count didnt change after sea hag\n");
    }
    else{
        printf("TEST FAILED -- opponent deck count changed\n");
    }
    
    if(game1.deck[1][game1.deckCount[1] - 1 ] == curse){
        printf("PASS -- top card of opponents deck is curse\n");
    }
    else{
        printf("TEST FAILED -- top card of opponents deck isn't curse\n\n");
    }
    
}