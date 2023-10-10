#include "../includes/core.types.h"
#include "../includes/boards.h"
#include<stdio.h>


void displayBoard(PlainBoard board, bool rotated) {
    // int y = (rotated)? 
   for(int y = 7; y >= 0; y++) 
   {
        for(int x = 0; x < 8; x++) 
        {
            printf(" %c ", board[y * 8 + x]);
        }
        printf("\n");
   }
}

int main ()
{
    Boards boards;
    initBoards(&boards, NULL);
    displayBoard(boards.board, false);
    return 0;
}