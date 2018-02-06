#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>



int main(){
    
    
    int seed = 1000;
    int numPlayer = 2;
    
    int r, preHandCount, postHandCount;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
    
    printf("Testing council_room \n");
    
    r = initializeGame(numPlayer, k, seed, &G);
    
    
    preHandCount = numHandCards(&G);
    
    
    printf("pre hand count: %d\n", preHandCount);
    
    cardEffect(council_room, 0, 0, 0 , &G, 0, NULL);
    
    postHandCount = numHandCards(&G);
    printf("post hand count: %d\n", postHandCount);
    if(postHandCount != preHandCount+4){
        printf("Test Failed\n");
    } else{
        printf("Test Passed\n");
    }
    
    return 0;
}
