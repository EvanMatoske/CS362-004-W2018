#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "rngs.h"

int checkSmithy(int p, struct gameState *post){
    
    
    int state;
    struct gameState preG;
    

    memcpy(&preG, post, sizeof(struct gameState));
    
    state = cardEffect(smithy, 0, 0, 0, post, 0, NULL);
    
    if (preG.handCount[0] + 3 != post->handCount[0]){
        printf("test fail");
        return 1;
    }
        
    return 0;
}


int main (){
    
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
    int state;
    struct gameState preG;
    int handPos = 0;
    int currentPlayer;
    
    for (n = 0; n < 2000; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        
        
        G.numPlayers = (rand() % 3) + 2;
        G.whoseTurn = rand() % G.numPlayers;
        currentPlayer = whoseTurn(&G);
        G.handCount[currentPlayer] = floor(Random() * MAX_HAND);
        G.deckCount[currentPlayer] = floor(Random() * MAX_DECK);
        G.discardCount[currentPlayer] = floor(Random() * MAX_DECK);
        handPos = (rand() % G.handCount[currentPlayer]);
        
        
        count += checkSmithy(p, &G);
    }
    printf("%d", state);
    return 0;
}

