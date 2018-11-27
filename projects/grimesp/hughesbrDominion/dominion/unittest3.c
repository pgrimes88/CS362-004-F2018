#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int p[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
           
    printf("unittest3.c\n");
    printf("updateCoins Function\n");
    struct gameState state;
    initializeGame(2, p, 20, &state);
    
    state.handCount[0] = 5;
    
    //this equates to 6 coins
    state.hand[0][0] = copper;
    state.hand[0][1] = silver;
    state.hand[0][2] = gold;
    state.hand[0][3] = province;
    state.hand[0][4] = adventurer;
    
    int test;
    
    test = updateCoins(0, &state, 0);
    if(state.coins == 6 && test == 0){
        printf("PASS -- correct # of coins -- one of each treasure\n");
    }
    else{
        printf("TEST FAILED\n");
        return 1;
    }
    
    //this equates to 5 coins
    state.hand[0][0] = copper;
    state.hand[0][1] = copper;
    state.hand[0][2] = copper;
    state.hand[0][3] = copper;
    state.hand[0][4] = copper;
    
    test = updateCoins(0, &state, 0);
    
    if(state.coins == 5 && test == 0){
        printf("PASS -- correct # of coins -- all copper\n");
    }
    else{
        printf("TEST FAILED\n");
        return 0;
    }
    
    //this equates to 10 coins
    state.hand[0][0] = silver;
    state.hand[0][1] = silver;
    state.hand[0][2] = silver;
    state.hand[0][3] = silver;
    state.hand[0][4] = silver;
    
    test = updateCoins(0, &state, 0);
    
    if(state.coins == 10 && test == 0){
        printf("PASS -- correct # of coins -- all silver\n");
    }
    else{
        printf("TEST FAILED\n");
        return 0;
    }
    
    //this equates to 15 coins
    state.hand[0][0] = gold;
    state.hand[0][1] = gold;
    state.hand[0][2] = gold;
    state.hand[0][3] = gold;
    state.hand[0][4] = gold;
    
    test = updateCoins(0, &state, 0);
    
    if(state.coins == 15 && test == 0){
        printf("PASS -- correct # of coins -- all gold\n");
    }
    else{
        printf("TEST FAILED\n");
        return 0;
    }
    
    //this equates to 0 coins
    state.hand[0][0] = smithy;
    state.hand[0][1] = adventurer;
    state.hand[0][2] = baron;
    state.hand[0][3] = council_room;
    state.hand[0][4] = gardens;
    
    test = updateCoins(0, &state, 0);
    
    if(state.coins == 0 && test == 0){
        printf("PASS -- correct # of coins -- no treasure\n");
    }
    else{
        printf("TEST FAILED\n");
        return 0;
    }
    
    //add 3 bonus coins
    test = updateCoins(0, &state, 3);
    
    if(state.coins == 3 && test == 0){
        printf("PASS -- bonus 3 added was correct\n");
    }
    else{
        printf("TEST FAILED\n");
        return 0;
    }
    
    //add 100 bonus coins
    test = updateCoins(0, &state, 100);
    
    if(state.coins == 100 && test == 0){
        printf("PASS -- bonus of 100 added was correct\n");
    }
    else{
        printf("TEST FAILED\n");
        return 0;
    }
    
    //add -5 bonus coins
    test = updateCoins(0, &state, -5);
    
    if(state.coins == -5 && test == 0){
        printf("PASS -- bonus of -5 added was correct\n");
    }
    else{
        printf("TEST FAILED\n");
        return 0;
    }
    
    //set hand to 0 
    state.handCount[0] = 0;
    test = updateCoins(0, &state, 0);
    if(state.coins == 0 && test == 0){
        printf("PASS -- handCount set to 0 means coins = 0\n");
    }
    else{
        printf("TEST FAILED\n");
        return 0;
    }
    
    printf("ALL TESTS SUCCESSFULLY COMPLETED\n\n");
}