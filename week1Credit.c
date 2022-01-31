#include <stdio.h>
#include <cs50.h>

int count = 0;
bool checking(long n);
int firstNum(long n);
int secondNum(long n);

int main(void)
{
    long number;
    do
    {
    number = get_long("Card number:");
    }
    while (!number);

    if (checking(number))
    {
        for (int i = 0; i < count -2; i++)
        {
            number /= 10;
        }

        if (count == 15 && (number == 34 || number == 37))
        {
            printf("AMEX\n");
        }
        else if (count == 16 && (number >= 51 && number <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((count == 13 || count == 16) && (number >= 40 && number <= 49))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// Luhn's algorithm checking function

bool checking(long n)
{
    int sum = 0;

    while (n)
    {
        if (n)
        {
        sum += firstNum(n);
        n /= 10;
        count++;
        }

        if (n)
        {
        sum += secondNum(n);
        n /= 10;
        count++;
        }
    }

    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int firstNum(long n)
{
    int a = n % 10;
    return a;
}


int secondNum(long n)
{
    int a, b, c;
    a = n % 10;
    a *= 2;
    b = a % 10;
    c = (a - b)/10;
    return b + c;
}