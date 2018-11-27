#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    printf("cardtest2.c\n");
    printf("adventurer\n");
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    struct gameState game1;
    initializeGame(2, k, 2, &game1);
    //printf("%d\n",whoseTurn(&game1));
    game1.hand[0][0] = adventurer;
    struct gameState gameOld;
    gameOld = game1;
    
    int bonus = 0;
    cardEffect(adventurer, 0, 0, 0, &game1, 0, &bonus);
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
    
    if(game1.handCount[0] - 2 == gameOld.handCount[0]){
        printf("PASS -- 2 cards were added to hand\n");
    }
    else{
        printf("TEST FAILED -- 2 cards weren't added to hands\n");
    }
    
    if(game1.deckCount[0] + 2 == gameOld.deckCount[0]){
        printf("PASS -- 2 cards were removed from deck\n");
    }
    else{
        printf("TEST FAILED -- 2 cards weren't removed from deck\n");
    }
    //printf("%d %d\n", game1.discardCount[0], gameOld.discardCount[0]);
    int counter = 0;
    while(1){
        counter++;
        if(game1.discardCount[0] > gameOld.discardCount[0]){
            printf("PASS -- Extra cards were sent to discard\n");
            break;
        }
        if(counter >= 50000){
            printf("TEST FAILED -- Extra cards were not sent to discard\n");
        }
        cardEffect(adventurer, 0, 0, 0, &game1, 0, &bonus);
    }
    
    initializeGame(2, k, 2, &game1);
    game1.hand[0][0] = adventurer;
    gameOld = game1;
    int counter2 = 0;
    int counter3 = 0;
    counter = 0;
    int counter4; 

    
    for(int i = 0; i < 60; i++){
        counter4 = 0;
        initializeGame(2, k, i+1000, &game1);
        game1.hand[0][0] = adventurer;
        gameOld = game1;
        updateCoins(0, &game1, 1000);
        game1.numBuys = 1000;
        game1.supplyCount[silver] = 10;

    
        if( i < 20){
            game1.deck[0][0] = silver;
            game1.deck[0][1] = silver;
            game1.deck[0][2] = silver;
            game1.deck[0][3] = silver;
            game1.deck[0][4] = silver;
            game1.deck[0][5] = silver;
        }
        else if ( i < 40){
            game1.deck[0][0] = gold;
            game1.deck[0][1] = gold;
            game1.deck[0][2] = gold;
            game1.deck[0][3] = gold;
            game1.deck[0][4] = gold;
            game1.deck[0][5] = gold;
        }

        cardEffect(adventurer, 0, 0, 0, &game1, 4124, &bonus);

        if(game1.hand[0][game1.handCount[0] - 1] == silver || game1.hand[0][game1.handCount[0] - 2] == silver){
            //printf("PASS -- %d %d\n",game1.hand[0][game1.handCount[0] - 1], game1.hand[0][game1.handCount[0] - 2]);
            counter4++;
            counter++;
        }
        if(game1.hand[0][game1.handCount[0] - 1] == gold || game1.hand[0][game1.handCount[0] - 2] == gold){
            counter4++;
            counter2++;
        }
        if(game1.hand[0][game1.handCount[0] - 1] == copper || game1.hand[0][game1.handCount[0] - 2] == copper){
            counter4++;
            counter3++;
        }
        
    }
    //printf("PASS --%d %d %d\n",counter2,counter, counter3);
    
    if(counter3 > 0){
        printf("Pass -- Copper was drawn from deck to hand\n");
    }
    else{
        printf("FAILED TEST\n");
    }
    
    if(counter > 0){
        printf("Pass -- Silver was drawn from deck to hand\n");
    }
    else{
        printf("FAILED TEST\n");
    }
    
    if(counter2 > 0){
        printf("Pass -- gold was drawn from deck to hand\n");
    }
    else{
        printf("FAILED TEST -- gold was not added from deck to hand \n\n");
    }
}