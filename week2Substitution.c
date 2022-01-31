#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>


int main(int argc, string key[])
{
    if (argc != 2)
    {
        return  1;
    }

    char arrayCopy[26][3];
    int count = 0;
    for (int i = 0, l = strlen(key[1]); i < l; i++)
    {
        if (isalpha(key[1][i]))
        {
            arrayCopy[i][0] = toupper(key[1][i]);
            arrayCopy[i][1] = 'A' + i;
            arrayCopy[i][2] = tolower(key[1][i]);
            count += (int) arrayCopy[i][0];
        }
        else
        {
            return 1;
        }
    }
    for (int k = 0; k < 26; k++)
    {
        for (int m = k + 1; m < 26; m++)
        {
            if (arrayCopy[k][0] == arrayCopy[m][0])
            {
                return  1;
            }
        }
    }

    if (count != 2015)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    string plainText = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, l = strlen(plainText); i < l; i++)
    {
        if (isalpha(plainText[i]))
        {
            int j = 0;
            while (toupper(plainText[i]) != arrayCopy[j][1])
            {
                j++;
            }

            if (isupper(plainText[i]))
            {
                printf("%c", arrayCopy[j][0]);
            }
            else
            {
                printf("%c", arrayCopy[j][2]);
            }

        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
}