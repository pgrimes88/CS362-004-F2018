#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    printf("cardtest3.c\n");
    printf("village\n");
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    struct gameState game1;
    initializeGame(2, k, 2, &game1);
    //printf("%d\n",whoseTurn(&game1));
    game1.hand[0][0] = village;
    struct gameState gameOld;
    gameOld = game1;
    
    int bonus = 0;
    cardEffect(village, 0, 0, 0, &game1, 0, &bonus);
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
    
    if(game1.handCount[1] == gameOld.handCount[1] && game1.deckCount[1] == gameOld.deckCount[1]  && whoseTurn(&game1) == whoseTurn(&gameOld)){
       printf("PASS -- Other players' states (hand, deck, action and turn remained the same).\n"); 
    }
    else{
        printf("TEST FAILED -- Other players' states changed\n");
    }
    if(game1.handCount[0]  == gameOld.handCount[0]){
        printf("PASS -- 1 card was added to hand\n");
    }
    else{
        printf("TEST FAILED -- 1 card1 wasn't added to hands\n");
    }
    if(game1.deckCount[0] + 1 == gameOld.handCount[0]){
        printf("PASS -- 1 card was drawn from deck\n");
    }
    else{
        printf("TEST FAILED -- 1 card wasn't drawn from deck\n");
    }
    if(game1.playedCardCount - 1  == gameOld.playedCardCount){
        printf("PASS -- 1 card was added to played pile\n");
    }
    else{
        printf("TEST FAILED -- 1 card1 wasn't added to played pile\n");
    }
    if(game1.numActions - 2  == gameOld.numActions){
        printf("PASS -- number of actions increased by 2\n");
    }
    else{
        printf("TEST FAILED --  number of actions not increased by 2\n");
    }
    
    printf("ALL TESTS SUCCESSFULLY COMPLETED\n\n");
    
}