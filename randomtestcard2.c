#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int checkCouncilRoom(int p, struct gameState *post){
    
    int state;
    struct gameState preG;
    
    memcpy(&preG, post, sizeof(struct gameState));
    
    state = cardEffect(council_room, 0, 0, 0, post, 0, NULL);
   
    
    if (preG.handCount[0] + 4 != post->handCount[0]){
        printf("test fail");
        return 1;
    }
    return 0;
    
}


int main () {
    
    int i, n, r, p, deckCount, discardCount, handCount;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};
    
    struct gameState G;
    
    printf ("Testing Smithy.\n");
    
    printf ("RANDOM TESTS.\n");
    
    SelectStream(2);
    PutSeed(3);
    int count;
    count = 0;
    
    for (n = 0; n < 1000; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        
        p = floor(Random() * 2);
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        G.numBuys = 0;
        count += checkCouncilRoom(p, &G);
    }
    printf("%d", count);
    return 0;
}

