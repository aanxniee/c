// import libraries
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float letter, word, sentence, grade; // declare variables as floats (results won't be)

int main(void)
{
    string text = get_string("Text: "); // ask user to enter the text

    int length = strlen(text); // find out the total length of the text entured

    // if the first character of text is alphanumeric, it is a word
    if (isalnum(text[0]))
    {
        word = 1;
    }

    // this loop checks each character in the text and increments by one
    for (int i = 0; i < length; i++)
    {
        if (isalnum(text[i])) // if the character is alphanumeri, it is a letter
        {
            letter++; // count the letters
        }
        // if there is a whitespace and the character after the whitespace is alphanumeric, it is a word
        if (i < length - 1 && isspace(text[i]) && (isalnum(text[i + 1]) || isalpha(text[i + 2])))
        {
            word++; // count the words
        }
        // if the character is an ending punctuation and the character before that is alphanumeric, it is a sentence
        if (i > 0 && (text[i] == '!' || text[i] == '?' || text[i] == '.') && isalnum(text[i - 1]))
        {
            sentence++; // count the sentences
        }

    }
    // calculate the grade using Coleman Liau's formula and round the grade
    grade = round(0.0588 * (100 * letter / word) - 0.296 * (100 * sentence / word) - 15.8);

    // display the grade as an integer
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)grade);
    }
}