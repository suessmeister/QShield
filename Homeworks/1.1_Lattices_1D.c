#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // this is because otherwise for whatever reason it gives us the same "random" number LOL 
    srand(time(NULL));
    int test = rand();
    printf("this number is %d", test);
    return 0;
}
