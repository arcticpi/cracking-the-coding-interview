// Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

#include <iostream>
#include <vector>

void ZeroMatrix(int **matrix, int m, int n)
{
    std::vector<int> columns;

    for (int i = 0; i < n; i++)
    {
        columns.push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        for (int t = 0; t < columns.size(); t++)
        {
            int j = columns.at(t);

            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < n; k++)
                {
                    matrix[i][k] = 0;
                }

                for (int k = 0; k < m; k++)
                {
                    matrix[k][j] = 0;
                }

                columns.erase(columns.begin() + t);

                break;
            }
        }
    }
}

void ShowMatrix(int **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int m = 16;
    int n = 8;
    int **matrix = new int *[m];

    for (int i = 0; i < m; i++)
    {
        matrix[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 1;
        }
    }

    matrix[2][1] = 0;
    matrix[0][3] = 0;

    ShowMatrix(matrix, m, n);

    ZeroMatrix(matrix, m, n);

    std::cout << std::endl;
    ShowMatrix(matrix, m, n);

    return 0;
}