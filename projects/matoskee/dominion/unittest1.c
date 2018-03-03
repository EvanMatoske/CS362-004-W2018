#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    
    
    int seed = 1000;
    int numPlayer = 2;
    
    int  r;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
    
    printf("Testing initializeGame()\n");
    
    r = initializeGame(numPlayer, k, seed, &G);
    
    if (r == 0){
        printf("Test Passed!\n");
    } else {
        printf("Test Failed\n");
    }

    
    return 0;
    
}
