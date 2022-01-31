#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

/*----------------------------------------------------------------------------*/
int main(void)
{
    string text = get_string("Text: ");
    int L = count_letters(text);
    int W = count_words(text);
    int S = count_sentences(text);
    float index = 0.0588 * (L*100/W) - (0.296 * (S*100/W)) - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

/*----------------------------------------------------------------------------*/
int count_letters(string text)
{
    int count = 0;

    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

/*----------------------------------------------------------------------------*/
int count_words(string text)
{
    int count = 1;

    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] == ' ' && text[i+1] != ' ')
        {
            count++;
        }
    }
    return count;
}

/*----------------------------------------------------------------------------*/
int count_sentences(string text)
{
    int count = 0;

    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}