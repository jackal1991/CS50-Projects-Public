#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool alpha_check(string s);
int shift(char c);

int main(int argc, string argv[])
{
    // check for two command-line args

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    else if (alpha_check(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;        
    }
    
    else
    {
        char *key_full = argv[1];
        int key_length = strlen(key_full);
        char *plaintext = get_string("Plaintext: ");
        int k = 0;
    
        //convert plaintext to cipher
        for (int i = 0; i < strlen(plaintext); i++)
        {
            if (isalpha(plaintext[i]) != 0)    
            {
                // determine specific key for character
                int key = shift(key_full[k % key_length]);             
                // increment k only if enciphering an alpha and *after* determining key                
                k++;
                
                //handle lowercase
                if (plaintext[i] > 96 && plaintext[i] < 123)
                {
                    //handle transforms that fall inside lowercase range
                    if (((plaintext[i] + key) % 52) + 52 > 96 && ((plaintext[i] + key) % 52) + 52 < 123)
                    {
                        plaintext[i] = ((plaintext[i] + key) % 52) + 52; 
                    }
                    //handle transforms that fall above lowercase range
                    else if (((plaintext[i] + key) % 52) + 104 > 122)
                    {
                        plaintext[i] = ((plaintext[i] + key) % 52) + 78;
                    }
                    //handle transforms that fall below lowercase range
                    else
                    {
                        plaintext[i] = ((plaintext[i] + key) % 52) + 104;
                    }
                }
                
                else
                    // handle Upper Case    
                {
                    // handle transforms that fall above uppercase range
                    if (((plaintext[i] + key) % 52) + 52 > 90)
                    {
                        plaintext[i] = ((plaintext[i] + key) % 52) + 26; 
                    }
                    // handle transforms that fall below uppercase range
                    else if (((plaintext[i] + key) % 52) + 52 < 65)
                    {
                        plaintext[i] = ((plaintext[i] + key) % 52) + 78;
                    }       
                    // handle transforms that fall in uppercase range
                    else
                    {
                        plaintext[i] = ((plaintext[i] + key) % 52) + 52;
                    }
                }  
            }              
        }
        printf("ciphertext: %s\n", plaintext);      
        return 0;
    }
}        

// Function to verify command-line arg is alpha
bool alpha_check(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if (isalpha(c) == 0)
        {
            return false;
        }
    }
    return true; 
}

// function to convert character in keyword to an integer [0 - 25]
int shift(char c)
{
    c = toupper(c);
    c = c - 65;
    return c;
}
