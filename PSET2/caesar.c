// import libraries
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2) // command line must have 2 arguments
    {
        printf("Usage: ./caesar key\n"); // else, it displays error
        return 1;
    }


    for (int ch = 0; ch < strlen(argv[1]); ch++) // check if each character in argv[1] is a number
    {
        if (argv[1][ch] < '0' || argv[1][ch] > '9') // if the character is not a number, it displays error message
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // convert arg[1] from a string to an integer and store it under variable
    int key = atoi(argv[1]);
    string text = get_string("plaintext: "); // asl the user for their plaintext
    printf("ciphertext: "); //display ciphertext

    // this loop runs for each character in in the plaintext
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z') // if the character is lower case letter, preserve the case
        {
            // rotate the letter as many times as the key using the formula
            char c = (((text[i] - 'a') + key) % 26) + 'a';
            printf("%c", c);
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') // if the character is upper case letter, preserve the case
        {
            // rotate the letter as many times as the key using the formula
            char c = (((text[i] + 'A') + key) % 26) + 'A';
            printf("%c", c);
        }
        else // else, display the character as it is
        {
            printf("%c", text[i]);
        }

    }
    printf("\n");
    return 0;
}

