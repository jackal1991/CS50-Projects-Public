//CS50 PS1
//Cash
//Jack Greaney

#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_change(string prompt);

int main(void)
{
    float dollars = get_change("Change owed: ");     
    int cents = round(dollars * 100); 
    int cents_remaining = cents;
    int coins = 0;
    
    if (cents_remaining != 0 && cents_remaining >= 25)
    {
        int quarters = cents_remaining / 25;
        cents_remaining = cents_remaining - (quarters * 25);
        coins = coins + quarters;
    }
    if (cents_remaining != 0 && cents_remaining >= 10)
    {
        int dimes = cents_remaining / 10;
        cents_remaining = cents_remaining - (dimes * 10);
        coins = coins + dimes;
    }
    if (cents_remaining != 0 && cents_remaining >= 5)
    {
        int nickels = cents_remaining / 5;
        cents_remaining = cents_remaining - (nickels * 5);
        coins = coins + nickels;        
    }
    if (cents_remaining != 0)
    {
        int pennies = cents_remaining;
        cents_remaining = cents_remaining - pennies;
        coins = coins + pennies;     
    }    
    printf("%i\n", coins);
}

// Prompt user for change owed in dollars and cents
float get_change(string prompt)
{
    float n;
    do
    {
        n = get_float("%s", prompt);
    }
    while (n < 0);
    return n;
}
