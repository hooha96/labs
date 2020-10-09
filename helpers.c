#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg = 0;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int r, g, b;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            r = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            g = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            b = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (r <= 255)
                image[i][j].rgbtRed = r;
            else if (r > 255)
                image[i][j].rgbtRed = 255;
            if (b <= 255)
                image[i][j].rgbtBlue = b;
            else if (b > 255)
                image[i][j].rgbtBlue = 255;
            if (g <= 255)
                image[i][j].rgbtGreen = g;
            else if (g > 255)
                image[i][j].rgbtGreen = 255;
        }
    }
    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int mid = round(width / 2);
    for (int i = 0; i < height; i++){
        for (int j = 0; j < mid; j++){
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Reflect image horizontally
/*
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp_r = 0, temp_g = 0, temp_b = 0;
    int x, y;
    for (int row = 0; row < height; row++){
        x = 0;
        y = width - 1;
        while (x < width){
            temp_r = image[row][x].rgbtRed;
            temp_g = image[row][x].rgbtGreen;
            temp_b = image[row][x].rgbtBlue;
            image[row][x].rgbtRed = image[row][y].rgbtRed;
            image[row][x].rgbtGreen = image[row][y].rgbtGreen;
            image[row][x].rgbtBlue = image[row][y].rgbtBlue;
            image[row][y].rgbtRed = temp_r;
            image[row][y].rgbtGreen = temp_g;
            image[row][y].rgbtBlue = temp_b;
            x++;
            y--;
        }
        x = 0;
        for (int j = width - 1; j >= 0; j--){
            temp_r1 = image[i][x].rgbtRed;
            temp_g1 = image[i][x].rgbtGreen;
            temp_b1 = image[i][x].rgbtBlue;
            temp_r2 = image[i][j].rgbtRed;
            temp_g2 = image[i][j].rgbtGreen;
            temp_b2 = image[i][j].rgbtBlue;
            image[i][x].rgbtRed = temp_r2;
            image[i][x].rgbtGreen = temp_g2;
            image[i][x].rgbtBlue = temp_b2;
            image[i][j].rgbtRed = temp_r1;
            image[i][j].rgbtGreen = temp_g1;
            image[i][j].rgbtBlue = temp_b1;
            x++;
        }
    }
    return;
}*/

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float r, g, b;
    float avg_r = 0, avg_g = 0, avg_b = 0;
    float n = 0;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            avg_r += image[i][j].rgbtRed;
            avg_g += image[i][j].rgbtGreen;
            avg_b += image[i][j].rgbtBlue;
            n++;
            if ((i-1) >= 0){
                avg_r += image[i-1][j].rgbtRed;
                avg_g += image[i-1][j].rgbtGreen;
                avg_b += image[i-1][j].rgbtBlue;
                n++;
            }
            if ((i+1) < height){
                avg_r += image[i+1][j].rgbtRed;
                avg_g += image[i+1][j].rgbtGreen;
                avg_b += image[i+1][j].rgbtBlue;
                n++;
            }
            if ((j-1) >= 0){
                avg_r += image[i][j-1].rgbtRed;
                avg_g += image[i][j-1].rgbtGreen;
                avg_b += image[i][j-1].rgbtBlue;
                n++;
            }
            if ((j+1) < width){
                avg_r += image[i][j+1].rgbtRed;
                avg_g += image[i][j+1].rgbtGreen;
                avg_b += image[i][j+1].rgbtBlue;
                n++;
            }
            if ((i-1) >= 0 && (j-1) >= 0){
                avg_r += image[i-1][j-1].rgbtRed;
                avg_g += image[i-1][j-1].rgbtGreen;
                avg_b += image[i-1][j-1].rgbtBlue;
                n++;
            }
            if ((i-1) >= 0 && (j+1) < width){
                avg_r += image[i-1][j+1].rgbtRed;
                avg_g += image[i-1][j+1].rgbtGreen;
                avg_b += image[i-1][j+1].rgbtBlue;
                n++;
            }
            if ((i+1) < height && (j-1) >= 0){
                avg_r += image[i+1][j-1].rgbtRed;
                avg_g += image[i+1][j-1].rgbtGreen;
                avg_b += image[i+1][j-1].rgbtBlue;
                n++;
            }
            if ((i+1) < height && (j+1) < width){
                avg_r += image[i+1][j+1].rgbtRed;
                avg_g += image[i+1][j+1].rgbtGreen;
                avg_b += image[i+1][j+1].rgbtBlue;
                n++;
            }
            r = avg_r / n;
            g = avg_g / n;
            b = avg_b / n;
            if (r > 255)
                r = 255;
            if (g > 255)
                g = 255;
            if (b > 255)
                b = 255;
            image[i][j].rgbtRed = (int) r;
            image[i][j].rgbtGreen = (int) g;
            image[i][j].rgbtBlue = (int) b;
            avg_r = 0;
            avg_g = 0;
            avg_b = 0;
            n = 0;
        }
    }
    return;
}
