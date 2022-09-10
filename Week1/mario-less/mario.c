#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);
int main(void)
{
    int number = get_positive_int("Height: "); //to get a number from a user

    for (int height = 0; height < number; height++) // for loop inside loop to build blocks
    {
        for (int dots = number - height - 2; dots >= 0; dots--)
        {
            printf(" ");
        }
        for (int row = 0; row <= height; row++) //loop for rows
        {
            printf("#");
        }
        printf("\n");
    }
}
int get_positive_int(string prompt)
{
    int number;
    do // do loop for runing code at least once
    {
        number = get_int("%s", prompt);
    }
    while (number < 1 || number > 8);
    return number; //will ask again if anything but 1-8 digits
}