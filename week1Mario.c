#include <stdio.h>
#include <cs50.h>

void space(int n);
void hash(int n);

int main(void)
{
    int height;

    do
    {
    height = get_int("Height:");
    }
    while (height < 1 || height > 8);


    for (int a = 1; a <= height; a++)
    {
        space(height - a);
        hash(a);
        space(2);
        hash(a);
        printf("\n");
    }
}

// Space function: n number
void space(int n)
{
    for (int i=0; i<n; i++)
    {
    printf(" ");
    }
}

// Hash function: n number
void hash(int n)
{
    for (int i=0; i<n; i++)
    {
    printf("#");
    }
}