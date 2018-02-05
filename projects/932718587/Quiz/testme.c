#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    
    int chooseRandChar[9] = {'[','(','{',' ',']',')','}','a','x'};
    int a;
    a = rand() % 9;
    return chooseRandChar[a];
    
}

char *inputString()
{
    // TODO: rewrite this function
    int i;
    int index, temp;
    int arraySize = 5;
    
    
    //tatic char randString[5];
    static char charSet[5] = {'r','e','e','s','t'};
    
    for (i = arraySize -1; i > 0; i--)
    {
        index = rand() % (i+1);
        temp = charSet[index];
        charSet[index] = charSet[i];
        charSet[i] = temp;
    }
    
    return charSet;
    
    
}

void testme()
{

  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    /*
    int i,a;
    char *s;
    for(i=0;i<10;i++){
        //a = inputChar();
        s = inputString();
        printf("%s\n", s);
    }
    */
    return 0;
}
