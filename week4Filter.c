#include "helpers.h"
#include <math.h>
#include <cs50.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            int red = image[r][c].rgbtRed;
            int green = image[r][c].rgbtGreen;
            int blue = image[r][c].rgbtBlue;
            int avg = round((red + green + blue) / 3);
            image[r][c].rgbtRed = avg;
            image[r][c].rgbtGreen = avg;
            image[r][c].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int mid = floor(width / 2);
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < mid; c++)
        {
            int red = image[r][width - (c + 1)].rgbtRed;
            int green = image[r][width - (c + 1)].rgbtGreen;
            int blue = image[r][width - (c + 1)].rgbtBlue;
            image[r][width - (c + 1)].rgbtRed = image[r][c].rgbtRed;
            image[r][width - (c + 1)].rgbtGreen = image[r][c].rgbtGreen;
            image[r][width - (c + 1)].rgbtBlue = image[r][c].rgbtBlue;
            image[r][c].rgbtRed = red;
            image[r][c].rgbtGreen = green;
            image[r][c].rgbtBlue = blue;
        }
    }
    return;
}

//Blur Function
int avg(int r, int c, int height, int width, char col, RGBTRIPLE image[height][width])
{
    int sum = 0, count = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if ((r + i) >= 0 && (r + i) < height && (c + j) >= 0 && (c + j) < width)
            {
                count++;
                if (col == 'r')
                sum += image[r + i][c + j].rgbtRed;
                if (col == 'g')
                sum += image[r + i][c + j].rgbtGreen;
                if (col == 'b')
                sum += image[r + i][c + j].rgbtBlue;
            }
        }
    }
    return round(sum / count);
}
    
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            copy[r][c].rgbtRed = image[r][c].rgbtRed;
            copy[r][c].rgbtGreen = image[r][c].rgbtGreen;
            copy[r][c].rgbtBlue = image[r][c].rgbtBlue;
        }
    }
    
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            image[r][c].rgbtRed = avg(r, c, height, width, 'r', copy);
            image[r][c].rgbtGreen = avg(r, c, height, width, 'g', copy);
            image[r][c].rgbtBlue = avg(r, c, height, width, 'b', copy);
        }
    }
    return;
}

// Edge function
int edg(int r, int c, int height, int width, char col, RGBTRIPLE image[height][width])
{
    int sumGx = 0;
    int sumGy = 0;
    int kernelX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int kernelY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if ((r - 1 + i) >= 0 && (r - 1 + i) < height && (c - 1 + j) >= 0 && (c - 1 + j) < width)
            {
                if (col == 'r')
                {
                    sumGx += (image[r - 1 + i][c - 1 + j].rgbtRed * kernelX[i][j]);
                    sumGy += (image[r - 1 + i][c - 1 + j].rgbtRed * kernelY[i][j]);
                }
                if (col == 'g')
                {
                    sumGx += (image[r - 1 + i][c - 1 + j].rgbtGreen * kernelX[i][j]);
                    sumGy += (image[r - 1 + i][c - 1 + j].rgbtGreen * kernelY[i][j]);
                }
                if (col == 'b')
                {
                    sumGx += (image[r - 1 + i][c - 1 + j].rgbtBlue * kernelX[i][j]);
                    sumGy += (image[r - 1 + i][c - 1 + j].rgbtBlue * kernelY[i][j]);
                }
            }
        }
    }
    int final = round(sqrt(pow(sumGx, 2) + pow(sumGy, 2)));

    if (final > 255)
    {
        final = 255;
    }
    if (final < 0)
    {
        final = 0;
    }

    return final;
}
// Detect edges


    
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    
    RGBTRIPLE copy[height][width];
    
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            copy[r][c].rgbtRed = image[r][c].rgbtRed;
            copy[r][c].rgbtGreen = image[r][c].rgbtGreen;
            copy[r][c].rgbtBlue = image[r][c].rgbtBlue;
        }
    }
    
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            image[r][c].rgbtRed = edg(r, c, height, width, 'r', copy);
            image[r][c].rgbtGreen = edg(r, c, height, width, 'g', copy);
            image[r][c].rgbtBlue = edg(r, c, height, width, 'b', copy);
        }
    }
    return;
}
