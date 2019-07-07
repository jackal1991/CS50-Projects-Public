#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check for two command-line args
    if (argc != 2 || argv[1] <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    //validate that key is digits
    string key_s = argv[1];
    for (int i = 0; i < strlen(key_s); i++)
    {
        if (isdigit(key_s[i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }  
    // convert string key to integer key
    int key = atoi(key_s);
    
    string plaintext = get_string("Plaintext: ");
    
    //convert plaintext to cipher
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]) != 0)
        {
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
