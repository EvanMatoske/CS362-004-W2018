FLAGS = -Wall -fpic -coverage -lm -std=c99

default: randomtest.out

randomtest.out: randomtestcard1.c randomtestcard2.c randomtestadventurer.c dominion.o rngs.o 

	echo "Result for running unit tests:" > randomtest.out
	
	echo "randomtestcard1.c:" >> randomtest.out
	gcc -o randomtest1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	./randomtest1 >> randomtest.out
	
	
	echo "randomtestcard2.c:" >> randomtest.out
	gcc -o randomtest2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	./randomtest2 >> randomtest.out
	
	
	echo "randomtestadventurer.c:" >> randomtest.out
	gcc -o randomadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randomadventurer >> randomtest.out
	

	



	


	
