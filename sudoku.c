//
//  main.c
//  sudoku solver
//
//  Created by Alaa on 12/02/2024.
//

#include <stdio.h>

void printSudoku(void);
int solveSudoku(int, int);
int sameCol(int, int, int);
int sameRow(int, int, int);
int sameSqr(int, int, int);

int sudoku[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};

int main(int argc, const char *argv[])
{

    printSudoku();
    printSudoku();
    printf("\n\n");
    if (solveSudoku(0, 0))
    {
        printf("Sudoku Solved:\n");
        printSudoku();
    }
    else
    {
        printf("No solution exists for the given Sudoku.\n");
    }
    return 0;
}

void printSudoku(void)
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            printf("---------------------\n");
        }
        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0 && j != 0)
            {
                printf("| ");
            }
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int solveSudoku(int x, int y)
{
    // If we've reached the end of the puzzle (bottom right corner), return 1 to indicate success
    if (x == 8 && y == 9)
        return 1;

    // If we've reached the end of the row, move to the next row
    if (y == 9)
    {
        x++;
        y = 0;
    }

    // If the cell is already filled, move to the next cell
    if (sudoku[x][y] != 0)
        return solveSudoku(x, y + 1);

    // Try placing numbers 1-9 in the cell
    for (int num = 1; num <= 9; num++)
    {
        // Check if the current number is valid in the current position
        if (!sameRow(x, y, num) && !sameCol(x, y, num) && !sameSqr(x, y, num))
        {
            // If the number is valid, place it in the cell
            sudoku[x][y] = num;

            // Recursively solve the rest of the puzzle
            if (solveSudoku(x, y + 1))
                return 1;

            // If we can't solve the puzzle with this number, backtrack and try the next number
            sudoku[x][y] = 0;
        }
    }
    // If no number works in this cell, return 0 to backtrack
    return 0;
}

int sameCol(int x, int y, int num)
{
    for (int i = 0; i < 8; i++)
    {
        if (sudoku[x][i] == num)
        {
            return 1;
        }
    }
    return 0;
}

int sameRow(int x, int y, int num)
{
    for (int i = 0; i < 8; i++)
    {
        if (sudoku[i][y] == num)
        {
            return 1;
        }
    }
    return 0;
}

int sameSqr(int x, int y, int num)
{

    // set x for rows within sqr
    if (x < 3)
    {
        x = 0;
    }
    else if (x < 6)
    {
        x = 3;
    }
    else
    {
        x = 6;
    }
    // set y for cols within sqr
    if (y < 3)
    {
        y = 0;
    }
    else if (y < 6)
    {
        y = 3;
    }
    else
    {
        y = 6;
    }

    // iterate over each sqr
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            if (sudoku[i][j] == num)
            {
                return 1;
            }
        }
    }
    return 0;
}
