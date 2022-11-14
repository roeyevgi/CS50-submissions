#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    string text = get_string("Text: ");
    printf("%s\n", text);
    // Number of letters in the text.
    int letters = count_letters(text);
    // Number of words in the text.
    int words = count_words(text);
    // Number of sentences in the text.
    int sentences = count_sentences(text);


    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    // Calculate Coleman-Liau formula.
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    // Print the relevant massage to the user.
    if (index <= 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }


}

int count_letters(string text)
{
    // Get the lenght of the text.
    int len = strlen(text);
    int letters = 0;
    // For each letter if it's an uppercase or lowercase add 1 to the counter.
    for (int i = 0; i < len; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            letters++;
        }
    }
    return letters;
}


int count_words(string text)
{
    int words = 0;
    int i = 0;
    // While it's not the end of the text, if the letter is a space add 1 to the counter.
    while (text[i] != '\0')
    {
        if (text[i] == ' ')
        {
            words++;
        }
        i++;
    }
    // Add extra 1 becouse the text ends without a space so an extra word needs to be counted.
    words++;
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    int i = 0;
    // While it's not the end of the text, if the letter is a '.' or '!' or '?' add 1 to the counter
    while (text[i] != '\0')
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        i++;
    }
    return sentences;
}

