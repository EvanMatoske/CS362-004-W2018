#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    
   
    int seed = 1000;
    int numPlayer = 2;
    
    int r;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
    int effect;
    printf("Testing Adventurer\n");
    
    r = initializeGame(numPlayer, k, seed, &G);
    
    effect = cardEffect(adventurer, 0, 0, 0, &G, 0, NULL);
    
    if (effect == 0){
        printf("Test passed\n");
    } else {
        printf("Test Failed\n");
    }
    
    
    return 0;
}
