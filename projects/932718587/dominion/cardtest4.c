#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>



int main(){
    
    
    int seed = 1000;
    int numPlayer = 2;
   
    int r, preHandCount, postHandCount, preActionCount, postActionCount;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
   
    printf("Testing Village \n");
    
    r = initializeGame(numPlayer, k, seed, &G);
    
    preHandCount = numHandCards(&G);
    preActionCount = G.numActions;
    
    printf("pre hand count: %d\n", preHandCount);
    printf("pre action count: %d\n", preActionCount);
    
    cardEffect(village, 0, 0, 0 , &G, 0, NULL);
    
    postHandCount = numHandCards(&G);
    postActionCount = G.numActions;
    
    printf("post hand count: %d\n", postHandCount);
    printf("post Action count: %d\n", postActionCount);
    
    if(postHandCount != preHandCount+1){
        printf("Test Failed\n");
    } else{
        printf("Test Passed\n");
    }
    
    if(postActionCount != preActionCount+2){
        printf("Test Failed\n");
    } else{
        printf("Test Passed\n");
    }
    
    
    return 0;
}
