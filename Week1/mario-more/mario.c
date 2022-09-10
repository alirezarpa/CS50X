#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Width: ");
    }
    while (!(height >= 1 && height <= 8));

    // n represents height and is a valid integer
    // betwwen 1 and 8
    //loop for rows
    for (int row = 1; row <= height; row++)
    {
        // print space to make it right aligned
        for (int k = 1; k <= height - row; k++)
        {
            printf(" ");
        }

        // print hashtag (#) for each row
        // print row number of times
        for (int j = 1; j <= row; j++)
        {
            printf("#");
        }
        printf(" ");
        printf(" ");

        //print row number of times
        for (int j = 1; j <= row; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}