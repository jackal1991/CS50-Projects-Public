#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);

// Build Mario Pyrimid
int main(void)
{
    int height = get_height("height: ");
    //outer loop cycles through height
    for (int i = 0; i < height; i++) 
    {
        //inner loops print spaces and sharps
        for (int j = -1 + height; j > i; j--) 
        {
            printf(" ");    
        }
        for (int k = 0; k <= i; k++) 
        {
            printf("#");    
        }
        printf("\n");
    }
}

// Prompt user for height integer between 0 - 8
int get_height(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}
