#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgbGray;

    // This loop changes the colour of the pixels in each column
    for (int i = 0; i < width; i++)
    {
        // This loop changes the colour of the pixels in each row
        for (int j = 0; j < height; j++) // This loop
        {
            // Average out the colour intensity
            // Round to the nearest whole number
            rgbGray = round((image[j][i].rgbtBlue + image[j][i].rgbtGreen + image[j][i].rgbtRed) / 3.00000);

            // Apply the colour change value to all colours
            image[j][i].rgbtBlue = rgbGray;
            image[j][i].rgbtRed = rgbGray;
            image[j][i].rgbtGreen = rgbGray;
        }
    }
}

// Set a limit on values to prevent overflow
int limit(int RGB)
{
    // If the RBG value is greater than 255, cap it at 255
    if (RGB > 255)
    {
        RGB = 255;
    }

    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed;
    float sepiaGreen;
    float sepiaBlue;

    // This loop changes the colour of the pixels in each column
    for (int i = 0; i < width; i++)
    {
        // This loop changes the colour of the pixels in each row
        for (int j = 0; j < height; j++)

        {
            // Calculate the sepia RGB colour values using the given formula
            // Round to the nearest whole number and make sure the value is between 0 and 255
            sepiaRed = limit(round(0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189 * image[j][i].rgbtBlue));
            sepiaGreen = limit(round(0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168 * image[j][i].rgbtBlue));
            sepiaBlue = limit(round(0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131 * image[j][i].rgbtBlue));

            // Apply colour change value to all colours
            image[j][i].rgbtRed = sepiaRed;
            image[j][i].rgbtGreen = sepiaGreen;
            image[j][i].rgbtBlue = sepiaBlue;

        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary array of 3 to store the pixels
    int temp[3];

    for (int j = 0; j < height; j++)
    {
        // Divide the width of the immage in two to reverse the image horizontally
        for (int i = 0; i < width / 2; i++)
        {
            // Store the pixels in first half to the temporary array
            temp[0] = image[j][i].rgbtRed;
            temp[1] = image[j][i].rgbtGreen;
            temp[2] = image[j][i].rgbtBlue;

            // Place the second half pixels to the empty first half
            image[j][i].rgbtRed = image[j][width - i - 1].rgbtRed;
            image[j][i].rgbtGreen = image[j][width - i - 1].rgbtGreen;
            image[j][i].rgbtBlue = image[j][width - i - 1].rgbtBlue;

            // Place the first half pixels stored in the temporary array to the empty second half
            image[j][width - i - 1].rgbtRed = temp[0];
            image[j][width - i - 1].rgbtGreen = temp[1];
            image[j][width - i - 1].rgbtBlue = temp[2];

        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary array to store the pixels
    RGBTRIPLE temp[height][width];

    // This loop blurs the pixels in each column
    // Create RGB variables to store the sum and a counter to find the average
    for (int i = 0, red, green, blue, counter; i < height; i++)
    {
        // This loop blurs the pixels in each row
        for (int j = 0; j < width; j++)
        {
            red = green = blue = counter = 0;

            // Find the neighbouring pixels and add the colour values to the sum
            if (i >= 0 && j >= 0) // The original pixel
            {
                red += image[i][j].rgbtRed;
                green += image[i][j].rgbtGreen;
                blue += image[i][j].rgbtBlue;
                counter++;
            }

            if (i >= 0 && j - 1 >= 0) // The pixel to the left of the original pixel
            {
                red += image[i][j - 1].rgbtRed;
                green += image[i][j - 1].rgbtGreen;
                blue += image[i][j - 1].rgbtBlue;
                counter++;
            }

            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width)) // The pixel to the right of he original pixel
            {
                red += image[i][j + 1].rgbtRed;
                green += image[i][j + 1].rgbtGreen;
                blue += image[i][j + 1].rgbtBlue;
                counter++;
            }

            if (i - 1 >= 0 && j >= 0) // The pixel above the original pixel
            {
                red += image[i - 1][j].rgbtRed;
                green += image[i - 1][j].rgbtGreen;
                blue += image[i - 1][j].rgbtBlue;
                counter++;
            }

            if (i - 1 >= 0 && j - 1 >= 0) // The pixel to the top left of the original pixel
            {
                red += image[i - 1][j - 1].rgbtRed;
                green += image[i - 1][j - 1].rgbtGreen;
                blue += image[i - 1][j - 1].rgbtBlue;
                counter++;
            }

            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width)) // The pixel to the top right of the original pixel
            {
                red += image[i - 1][j + 1].rgbtRed;
                green += image[i - 1][j + 1].rgbtGreen;
                blue += image[i - 1][j + 1].rgbtBlue;
                counter++;
            }

            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0)) // The pixel below the original pixel
            {
                red += image[i + 1][j].rgbtRed;
                green += image[i + 1][j].rgbtGreen;
                blue += image[i + 1][j].rgbtBlue;
                counter++;
            }

            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0)) // The pixel to the bottom left of the original pixel
            {
                red += image[i + 1][j - 1].rgbtRed;
                green += image[i + 1][j - 1].rgbtGreen;
                blue += image[i + 1][j - 1].rgbtBlue;
                counter++;
            }

            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width)) // The pixel to the bottom right of the original pixel
            {
                red += image[i + 1][j + 1].rgbtRed;
                green += image[i + 1][j + 1].rgbtGreen;
                blue += image[i + 1][j + 1].rgbtBlue;
                counter++;
            }

            // Find the average of the sum of the neighbouring pixels
            temp[i][j].rgbtRed = round(red / (counter * 1.0));
            temp[i][j].rgbtGreen = round(green / (counter * 1.0));
            temp[i][j].rgbtBlue = round(blue / (counter * 1.0));
        }
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // Copy the values from the temporary table to the image
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
        }
    }
}

