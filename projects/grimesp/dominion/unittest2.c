#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void setSupplies(struct gameState *state){
    state->supplyCount[0] = 10;
    state->supplyCount[1] = 10;
    state->supplyCount[2] = 10;
    state->supplyCount[3] = 10;
    state->supplyCount[4] = 10;
    state->supplyCount[5] = 10;
    state->supplyCount[6] = 10;
    state->supplyCount[7] = 10;
    state->supplyCount[8] = 10;
    state->supplyCount[9] = 10;
    state->supplyCount[10] = 10;
    state->supplyCount[11] = 10;
    state->supplyCount[12] = 10;
    state->supplyCount[13] = 10;
    state->supplyCount[14] = 10;
    state->supplyCount[15] = 10;
    state->supplyCount[16] = 10;
    state->supplyCount[17] = 10;
    state->supplyCount[18] = 10;
    state->supplyCount[19] = 10;
    state->supplyCount[20] = 10;
    state->supplyCount[21] = 10;
    state->supplyCount[22] = 10;
    state->supplyCount[23] = 10;
    state->supplyCount[24] = 10;
    state->supplyCount[25] = 10;
    state->supplyCount[26] = 10;
}

int main(){
    int p[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
           
    printf("unittest2.c\n");
    printf("isGameOver Function\n");
    //initialized to random value 
    int test = 500;
    
    struct gameState state2;
    initializeGame(2, p, 20, &state2);
    test = isGameOver(&state2);
    if(test == 0){
        printf("PASS -- Game is not over after initializing gamestate\n");
    }
    else{
        printf("TEST FAILED \n");
        return 0;
    }
    
    printf("Set each cards supplycount to 10\n");
    struct gameState state;
    setSupplies(&state);
    
    //make sure you don't get return of 1 when province is not 0
    //expect a return value of 0
    test = isGameOver(&state);
    if(test == 0){
        printf("PASS -- game is not over when province count > 0\n");
    }
    else{
        printf("TEST FAILED\n");
        return 0;
    }
    
    //test for 0 province count
    //expected return of 1;
    state.supplyCount[province] = 0;
    test = isGameOver(&state);
    if(test == 1){
        printf("PASS -- game is over when province count == 0\n");
    }
    else{
        printf("TEST FAILED\n");
        return 0;
    }
    
    //Test if having 3 or more supply piles at 0 will end game
    //expect return value of 1 
    state.supplyCount[copper] = 0;
    state.supplyCount[silver] = 0;
    state.supplyCount[gold] = 0;
    test = isGameOver(&state);
    if(test == 1){
        printf("PASS -- game is over when 3 supply piles are 0\n");
    }
    else{
        printf("TEST FAILED\n");
        return 0;
    }
    
    setSupplies(&state);
    state.supplyCount[salvager] = 0;
    state.supplyCount[sea_hag] = 0;
    state.supplyCount[treasure_map] = 0;
    test = isGameOver(&state);
    printf("Setting only last 3 supply piles equal to 0\n");
    if(test == 1){
        printf("PASS -- game is over when 3 supply piles are 0\n");
    }
    else{
        printf("TEST FAILED\n\n");
        return 0;
    }
    printf("ALL TESTS SUCCESSFULLY COMPLETED\n\n");
}