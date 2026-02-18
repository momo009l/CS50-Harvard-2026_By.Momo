#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");

    int sum = 0;
    long n = number;
    int position = 0;

    while (n > 0)
    {
        int digit = n % 10;

        if (position % 2 == 1)
        {
            int doubled = digit * 2;
            sum += doubled / 10 + doubled % 10;
        }
        else
        {
            sum += digit;
        }

        n /= 10;
        position++;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    int length = 0;
    long start = number;

    while (start >= 100)
    {
        start /= 10;
        length++;
    }
    length += 2;

    if (length == 15 && (start == 34 || start == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (start >= 51 && start <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && (start / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
