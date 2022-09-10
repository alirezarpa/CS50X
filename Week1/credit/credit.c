#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_length(long number);
int get_sum_right(long number, int length);
int get_sum_left(long number, int length);
int get_number_at(long number, int index, int offset);

int main(void)
{
    long number = get_long("Number: ");
    int length = get_length(number);

    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    int sum_right = get_sum_right(number, length);
    int sum_left = get_sum_left(number, length);
    int total = sum_right + sum_left;

    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    int start = get_number_at(number, length, 2);

    if (start == 34 || start == 37)
    {
        printf("AMEX\n");
    }
    else if (start >= 51 && start <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_length(long number)
{
    int i = 0;
    while (number > 0)
    {
        number = number / 10;
        i++;
    }
    return i;
}

int get_sum_right(long number, int length)
{
    int sum = 0;

    for (int i = 2; i <= length; i += 2)
    {
        int digit = get_number_at(number, i, 1) * 2;
        sum += digit < 10 ? digit : 1 + (digit % 10);
    }

    return sum;
}

int get_sum_left(long number, int length)
{
    int sum = 0;

    for (int i = 1; i <= length; i += 2)
    {
        sum += get_number_at(number, i, 1);
    }

    return sum;
}

int get_number_at(long number, int index, int offset)
{
    long pow1 = pow(10, index);
    long pow2 = pow(10, index - offset);
    return (number % pow1) / pow2;
}