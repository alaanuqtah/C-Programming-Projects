//
//  main.c
//  Tic Tac Toe Game
//
//  Created by Alaa on 06/02/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'Y';

void resetBoard(void);
void printBoard(void);
int checkFreeSpace(void);
void playerMove(void);
char computerMove(void);
char checkWinner(void);
void printWinner(char);

int main(int argc, const char *argv[])
{

    char winner = ' ';
    char resp;

    do
    {
        winner = ' ';
        resp = ' ';
        resetBoard();

        while (winner == ' ' && checkFreeSpace() != 0)
        {
            printBoard();

            playerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpace() == 0)
            {
                break;
            }

            computerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpace() == 0)
            {
                break;
            }
        }
        printBoard();
        printWinner(winner);

        printf("\nWanna play again? (y/n) :");
        scanf("%c");
        scanf("%c", &resp);
        resp = toupper(resp);

    } while (resp == 'Y');

    printf("THANKS BYEE!!");

    return 0;
}

void resetBoard(void)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard(void)
{
    // separator string
    const char *separator = "---|---|---\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2)
        {
            printf("%s", separator);
        }
    }
}

int checkFreeSpace(void)
{

    int freeSpc = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpc--;
            }
        }
    }
    return freeSpc;
}
void playerMove(void)
{

    int x, y;
    do
    {
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ')
        {
            printf("INVALID!!");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}
char computerMove(void)
{
    srand(time(0));
    int x;
    int y;

    if (checkFreeSpace() > 0)
    {

        do
        {
            x = rand() % 3;
            y = rand() % 3;

        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }

    return ' ';
}

char checkWinner(void)
{

    // winning by row
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    // winning by column
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[i][0] == board[2][i])
        {
            return board[0][i];
        }
    }

    // winning by diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][0];
    }

    return ' ';
}
void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("You WINNN!!!");
    }
    else if (winner == COMPUTER)
    {
        printf("YOU LOSTTT!!");
    }
    else
    {
        printf("it's a tie");
    }
}
