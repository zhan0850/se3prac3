#include <stdio.h>
#include <stdlib.h>
#include "2048.h"

int **board_create(int size)
{
  int i;
  // make sure size of board is sensible
  if (size<1||size>255) return NULL;

  int **board=calloc(size,sizeof(int *));
  if (!board) return NULL;
  for(i=0;i<size;i++) {
    board[i]=calloc(size,sizeof(int));
    if (!board[i]) return NULL;
  }
  return board;
}

int board_display(int size,int **board)
{
  // make sure size of board is sensible
  if (size<1||size>255) return -1;
  
  int x,y;
  
  for(y=0;y<size;y++) {    
    for(x=0;x<size;x++) {
      if (board[x][y]) printf("[% 5d]",board[x][y]);
      else printf("[     ]");
    }
    printf("\n");
  }
  return 0;
}

void board_spawn_tile(int size,int **board) {
	int col, row;
	
	//find an empty spot
	do {
		col = random()%size;
		row = random()%size;
	}
	while(board[col][row]);
	
	//fill something into the spot
	int rand = random()%5;	//1/5 chance to have a 4, 4/5 chance to have a 2
	if(rand == 4)
		board[col][row] = 4;
	else
		board[col][row] = 2;
	
}