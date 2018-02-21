#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "rngs.h"



int checkAdventurer(int p, struct gameState *post){
    
    int state;
    struct gameState preG;
    
    memcpy(&preG, post, sizeof(struct gameState));
    
    state = cardEffect(adventurer, 0, 0, 0, post, 0, NULL);
    
    //printf("Adventurer Card");
    
    if (preG.handCount[0] + 2 != post->handCount[0]){
        return 1;
    }
    return 0;
}

int main () {
    
    int i, n, r, p, deckCount, discardCount, handCount;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};
    
    struct gameState G;
    
    printf ("Testing Adventurer.\n");
    
    printf ("RANDOM TESTS.\n");
    
    SelectStream(2);
    PutSeed(3);
    int count;
    count = 0;
    
    for (n = 0; n < 2000; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        p = floor(Random() * 2);
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        count += checkAdventurer(p, &G);
    }
    printf("%d", count);
    return 0;
}
