//CS50 PS1
//Credit
//Jack Greaney

#include <cs50.h>
#include <stdio.h>
#include <math.h>

long get_credit_card(string prompt);
long two_digits(long n);
long one_digit(long n);
long num_digits(long n);

int main(void)
{
    // Prompt user for credit card number
    long number_in = get_credit_card("Number: ");
    
    // checksum using modulo
    long sum_notlast = 0;
    long number_i = number_in;
    long number_j = number_i;
    long number_k;
    long number_l;
    long digits = num_digits(number_in);
    
    //Every other number starting with next-to-last
    while (number_i)
    {
        number_j = number_i;
        number_j = number_j / 10;
        number_j = number_j % 10;
        number_i = number_i / 100;
        number_j = 2 * number_j;
        if (number_j >= 10)
        {
            number_k = (number_j / 10) % 10;
            number_l = number_j % 10;
        }
        else
        {
            number_k = number_j;
            number_l = 0;
        }
        sum_notlast = sum_notlast + number_k + number_l;
    }
    long sum_last = 0;
    number_i = number_in;
    number_j = number_i;
    
    //sum unused digits
    while (number_i)
    {
        number_j = number_i;
        number_j = number_j % 10;
        number_i = number_i / 100;
        sum_last = sum_last + number_j;
    }
    
    // complete checksum
    long sum_of_sums = sum_notlast + sum_last;
    
    // evaluate checksum and exit if failed
    if (sum_of_sums % 10 != 0)
    {
        printf("INVALID\n");
    }
    
    // identify credit card type
    else if ((two_digits(number_in) == 34 || two_digits(number_in) == 37) && digits == 15)
    {
        printf("AMEX\n");
    }
    
    else if (two_digits(number_in) >= 51 && two_digits(number_in) <= 55 && digits == 16)
    {
        printf("MASTERCARD\n");
    }
    
    else if (one_digit(number_in) == 4 && (digits == 13 || digits == 16))
    {
        printf("VISA\n");
    }
    
    // exit if checksum valid but credit card type unknown
    else
    {
        printf("INVALID\n");
    }
}

// HELPER FUNCTIONS

// Prompt user for credit card number 
long get_credit_card(string prompt)
{
    long n;
    do
    {
        n = get_long("%s", prompt);
    }
    while (n < 0);
    return n;
}

//get first two digits of credit card
long two_digits(long n)
{
    while (n >= 100)
    {
        n = n / 10;
    }
    return n;
}

//get first digit of credit card
long one_digit(long n)
{
    while (n >= 10)
    {
        n = n / 10;
    }
    return n;
}

//Count digits

long num_digits(long n)
{
    long count = 0;
    while (n != 0)
    {
        count++;
        n = n / 10;
    }
    return count;
}
