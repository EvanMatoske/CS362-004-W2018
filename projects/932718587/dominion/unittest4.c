#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    
    
    int seed = 1000;
    int numPlayer = 2;
    
    int p, r;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
    
    printf("Testing whoseturn()\n");
    
    initializeGame(numPlayer, k, seed, &G);
    p = G.whoseTurn;
    r = whoseTurn(&G);
    
    
    if (r == p){
        printf("Test Passed!\n");
    } else {
        printf("Test Failed\n");
    }
    
    
    return 0;
    
}

