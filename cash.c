// import libraries
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // create variables
    float amount; // amount is the amount of change entered by the user
    int cents = 0; // cents is the amount of change in cents
    int count = 0; // count is the number of coins needed
    int amount_left = 0; // amount_left is the amount of change left

    // this do-while loops if the user puts in invalid input
    do
    {
        amount = get_float("Change owed: ");
    }
    while (amount <= 0); // ensures input is positive

    cents = (int)round(amount * 100);

    amount_left = cents;
    count += amount_left / 25;  // this counts the number of quarters
    amount_left %= 25;

    count += amount_left / 10;  // this counts the number of dimes
    amount_left %= 10;

    count += amount_left / 5;  // this counts the number of nickels
    amount_left %= 5;

    count += amount_left; // this counts the number of pennies

    // display the count of coins
    printf("You get %d coins\n", count);
}