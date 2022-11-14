#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Key validation.
    if (argc != 2)
    {
        printf("Usage: ./subtitution KEY\n");
        return 1;
    }

    string key = argv[1];
    int key_length = strlen(key);
    if (key_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < key_length; i++)
    {
        // Check for non alphabetic caracters.
        if (isalpha(key[i]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        // Check for repeated characters.
        for (int j = i + 1; j < key_length; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }


    }


    // Get plaintext.
    string plaintext = get_string("Plaintext: ");
    int text_len = strlen(plaintext);

    // Encipher.
    string ciphertext[text_len];
    printf("ciphertext: ");
    // Print the ciphertext letter by letter.
    for (int i = 0; i < text_len; i++)
    {
        // If it is an uppercase letter print the relevant key letter in uppercase.
        if (isupper(plaintext[i]))
        {
            printf("%c", toupper(key[(int)plaintext[i] - 65]));

        }
        // If it is an lowercase letter print the relevant key letter in lowercase.
        else if (islower(plaintext[i]))
        {
            printf("%c", tolower(key[(int)plaintext[i] - 97]));
        }
        // Print any character that is not a letter as is.
        else
        {
            printf("%c", plaintext[i]);
        }

    }
    printf("\n");


}