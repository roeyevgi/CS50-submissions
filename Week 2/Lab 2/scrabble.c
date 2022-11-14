#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    int len = strlen(word);
    // For each letter in word check if it's lower of upper. if it's a symbol it will return 0 so it will be ignored.
    for (int i = 0; i < len; i++)
    {
        if (islower(word[i]))
        {
            // Substruct the ASCII value of the letter 'a' from the ASCII value of the currnt letter in word.
            // in order to get the excect location in the English alphabeth and get the right position in POINTS.
            score += POINTS[(int)word[i] - 97];
        }
        else if (isupper(word[i]))
        {
            // Substruct the ASCII value of the letter 'A' from the ASCII value of the currnt letter in word.
            // in order to get the excect location in the English alphabeth and get the right position in POINTS.
            score += POINTS[(int)word[i] - 65];
        }
    }

    return score;
}
