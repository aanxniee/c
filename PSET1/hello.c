// import libraries
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // prompt the user to enter their name as a string
    string name = get_string("What is your name: ");
    // print hello and the user input
    printf("hello, %s\n", name);
}
