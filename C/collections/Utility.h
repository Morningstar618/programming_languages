#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void DiceRoll(int n)
{
    srand(time(NULL));

    for (int i = 1; i <= n; i++)
    // return rand() % 6 + 1;
    {
        int roll = rand() % 6 + 1;
        printf("Dice #%d: %d\n", i, roll);
    }
}