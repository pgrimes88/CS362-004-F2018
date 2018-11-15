#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    printf("Random Test Smithy.c\n");
    srand(time(0)); 
    int seed;
    int numberofPlayers;
    int currentPlayer;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    struct gameState game1;
    struct gameState gameOld;


    int test1PassCount = 0;
    int test2PassCount = 0;
    int test3PassCount = 0;
    int test4PassCount = 0;

    int counter = 0;
    while(1){
        
        seed =  rand();
        numberofPlayers = 1 + rand()%2; // minumum of 2 with max of 4;
        
        initializeGame(numberofPlayers, k, seed, &game1);
        
        currentPlayer += 1;
        if(currentPlayer > numberofPlayers){
            currentPlayer = 0;
        }
        
        game1.whoseTurn = currentPlayer;
        
        //make random deck
        game1.deckCount[currentPlayer] = 0;
        int changeCards = rand()%10;
        int j;
        for (j = 0; j < 9 + changeCards; j++)
    	{
    	  game1.deck[currentPlayer][j] = rand()%27;
    	  game1.deckCount[currentPlayer]++;
    	}
    	
    	//make sure there are treasures in deck
    	for (j = 9 + changeCards; j < 50 + changeCards; j++)
    	{
    	  int randomMoney = rand()%3 +4;
    	  game1.deck[currentPlayer][j] = randomMoney;
    	  game1.deckCount[currentPlayer]++;
    	}
    	
    	
    	changeCards = rand()%4;
    	//discard a random amount of cards
    	game1.discardCount[currentPlayer] = 0;
    	int p;
    	for(p = 0; p < changeCards; p++){
    	    game1.discard[currentPlayer][p] = rand()%27;
    	    game1.discardCount[currentPlayer]++;
    	}
    	
    	//add cards to hand to change hand size
    	int k;
    	for(k=0; k < changeCards; k++){
    	    drawCard(currentPlayer, &game1);
    	}
    	
    	int bonus = 0;
    	//printf("%d\n",game1.handCount[currentPlayer]);
    	isGameOver(&game1);
    	//call other cards
    	if(counter < 300){
    	    cardEffect(rand()%27, 0, 0, 0, &game1, 0, &bonus);
    	}

    	playCard(rand()%27, -1, -1, -1, &game1);
    	buyCard(rand()%27, &game1);
    	gameOld = game1;
    	
    	bonus = 0;
        cardEffect(smithy, 0, 0, 0, &game1, 0, &bonus);
        int test = 0;
        for(int i = 0; i < 27; i++){
            if(game1.handCount[j] == gameOld.handCount[j] && game1.deckCount[j] == gameOld.deckCount[j] && game1.numActions == gameOld.numActions && whoseTurn(&game1) == whoseTurn(&gameOld)){
                //
            }
            else{
                test = 1;
            }
        
        }
        int tempPass = 0;
        for(j = 0; j <= numberofPlayers; j++){
            if(j != currentPlayer){
                if( 1 == 1){
                    tempPass += 1;
                }
            }
        }
        
        
    	//printf("player: %d\n",currentPlayer);
    	
    	//test #1 -- supplycount unchanged
    	if(test == 0){
            test1PassCount+=1;
        }
        
        //test #2 -- other players unchanged (handcount, deckcount, actions and whoseturn)
        if(tempPass == numberofPlayers){
            test2PassCount+=1;
        }

        //test #3 -- handcount was changed of current player
        

        if(game1.handCount[currentPlayer] - 3 == gameOld.handCount[currentPlayer]){
            test3PassCount +=1;
        }
        
        //test #4 -- deckcount was changed of current player
        if(game1.deckCount[currentPlayer] + 3 == gameOld.deckCount[currentPlayer]){
            test4PassCount +=1;
        }
        
    	counter++;
        if (counter > 49999){
            break;
        }
    }
    
    printf("Test #1 Pass count %d/50000  (Supply Count Unchanged)\n", test1PassCount);
    printf("Test #2 Pass count %d/50000  (other players unchanged (handcount, deckcount, actions and whoseturn))\n", test2PassCount);
    printf("Test #3 Pass count %d/50000  (handcount was changed of current player)\n", test3PassCount);
    printf("Test #4 Pass count %d/50000  (deckcount was changed of current player\n", test4PassCount);

}
