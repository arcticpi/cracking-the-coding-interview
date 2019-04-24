// Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
// write a method to rotate the image by 90 degrees. Can you do this in place?

#include <iostream>

char *RotateMatrix(char *matrix, int n)
{
    char *output = new char[n * n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            output[i * n + j] = matrix[j * n + (n - 1 - i)];
        }
    }

    return output;
}

void ShowMatrix(char *matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << matrix[i * n + j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    char *matrix = "0123456789ABCDEF";
    int n = 4;

    ShowMatrix(matrix, n);
    std::cout << std::endl;
    ShowMatrix(RotateMatrix(matrix, n), n);

    return 0;
}