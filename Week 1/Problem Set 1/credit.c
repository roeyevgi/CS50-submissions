#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_num;
    int sum1 = 0;
    int sum2 = 0;
    // For temp use.
    int x;
    int digit1;
    int digit2;
    int total_sum = 0;
    int card_length = 0;
    //sd = starting digits
    int sd;

    // Promp for input
    card_num = get_long("Please enter you credit card number: ");
    // For temp use.
    long num = card_num;

    // Calculate checksum
    do
    {
        // Extract the last digit
        x = num % 10;
        // Remove the last digit from num.
        num /= 10;
        sum1 += x;
        // Extract the (new) last digit and remove it from the number (the second last)
        x = num % 10;
        x = (x * 2);
        num /= 10;
        digit1 = x % 10;
        digit2 = x / 10;
        sum2 += digit1 + digit2;
    }
    while (num > 0);

    total_sum = sum1 + sum2;

    // Checks Luhn’s Algorithm for card validation.
    if (total_sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Check for cand length and starting digits
    num = card_num;
    while (num > 0)
    {
        card_length++;
        num /= 10;
    }

    // Get the first 2 digits of the card.
    num = card_num;
    do
    {
        num /= 10;
    }
    while (num > 100);
    sd = num;

    // Checks the card's company.
    if (card_length == 15 && (sd == 34 || sd == 37))
    {
        printf("AMEX\n");
    }
    else if (card_length == 16 && (sd == 51 || sd == 52 || sd == 53 || sd == 54 || sd == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((card_length == 13 || card_length == 16) && (sd / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}