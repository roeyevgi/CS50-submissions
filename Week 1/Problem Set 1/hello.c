#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get user name
    string name = get_string("What is your name? ");
    //prints user name
    printf("Hello, %s\n", name);
}