/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
void printChessBoard(int board[8][8]);
int isValid(int row, int col);
void fillTable(int table[8][8], int board[8][8]);
int nextMove(int row, int col, int board[8][8], int table[8][8], int *nextR, int *nextC);
int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main()
{
    
    int board[8][8] = {0};
    int table[8][8] = {0};
    printChessBoard(board);
    printf("\n");
    fillTable(table, board);
    printChessBoard(table);
    
    int row = 0;
    int col = 0;
    int fullTours = 0;
    
    //touring from every possible cell
    for (row = 0; row < 8; row++) {
        for (col = 0; col < 8; col++) {
            int moveCounter = 1;
            int nextR = 0, nextC = 0;
            int r = row;
            int c = col;
            //clear the board
            memset(board, 0, 8*8*sizeof(int));
            board[row][col] = moveCounter;
            fillTable(table, board);
            //touring the board while their are possible moves
            while (nextMove(r, c, board, table, &nextR, &nextC) < 9) {
                r = nextR;
                c = nextC;
                board[r][c] = ++moveCounter;
                fillTable(table, board);
            }
            
            //keeps track of full tours
            if (moveCounter == 64) {
                fullTours++;
            }
            
        }
    }
    
    //clears chess board
    printChessBoard(board);
    printf("\n");
    printChessBoard(table);
    
    printf("There were %d full tours out of 64\n", fullTours);
    
    return 0;
}

//print chess board
void printChessBoard(int board[8][8])
{
    for(int i=0; i < 8; i++)
    {
        for(int j=0; j < 8; j++)
        {
            printf("%3d ", board[i][j]);
        }
        printf("\n");
    }
}

//filling the accessibility table with accessible positions
void fillTable(int table[8][8], int board[8][8])
{
    for(int i=0; i<8;i++)
    {
        for(int j=0; j< 8; j++)
        {
            int access = 0;
            
            //counts # of accessible positions
            for(int count=0; count < 8; count++)
            {
                int row = i+vertical[count];
                int col = j+horizontal[count];
                if(isValid(row, col) && board[row][col]==0)
                {
                    access++;
                }
            }
            
            table[i][j] = access;
        }
    }
}

//checks for valid moves
int isValid(int row, int col)
{
    if(row >= 0 && row < 8 && col >= 0 && col < 8)
    {
        return 1;
    } 
    return 0;
}

//finds the next move by using the accessibility heuristic
int nextMove(int row, int col, int board[8][8], int table[8][8], int *nextR, int *nextC) {
    int min = 9;
    int minR, minC;
    
    //finds the cell with lowest accessibility
    for(int count=0; count < 8; count++)
    {
        int r = row+vertical[count];
        int c = col+horizontal[count];
        if(isValid(r, c) && board[r][c]==0)
        {
            if(table[r][c] < min)
            {
                min = table[r][c];
                minR = r;
                minC = c;
            }
        }
    }
    
    //returns the next move
    *nextR = minR;
    *nextC = minC;
    return min;
    
}