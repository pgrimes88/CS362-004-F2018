#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("unittest4.c\n");
    printf("kingdomCards Function\n");
    srand(time(NULL));
    int array[10];
    int *k;
    int test = 0;
    int i;
    for(i = 0; i < 10; i++){
        array[i] = rand()%27;
    }
    k = kingdomCards(array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8], array[9] );
    for(i = 0; i < 10; i++){
        if(array[i] != k[i]){
            test = 1;
        }
    }
    if(test == 0){
        printf("PASS -- the random numbers passed to kingdomCards are the same as the array returned from it\n");
    }
    else{
        printf("TEST FAILED\n");
        return 0;
    }
    
    test = 0;
    int p[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    
    k = kingdomCards(p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9] );
    for(i = 0; i < 10; i++){
        if(p[i] != k[i]){
            test = 1;
        }
    }
    
    if(test == 0){
        printf("PASS -- the 10 cards passed to kingdomCards are the same as the array returned from it\n");
    }
    else{
        printf("TEST FAILED\n");
        return 0;
    }
    
    struct gameState state;
    initializeGame(2, k,2, &state);
    int test2 = isGameOver(&state);
    if(test2 == 0){
        printf("PASS -- Game is not over after initializing with new array\n");
    }
    else{
        printf("TEST FAILED \n");
        return 0;
    }
    
    printf("ALL TESTS SUCCESSFULLY COMPLETED\n\n");
}