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

int board_rotate_90(int size,int **board)
{
  // make sure size of board is sensible
  if (size<1||size>255) return -1;
  
  int temp_board[size][size];
  int x,y;

  // rotate into temp_board
  for(x=0;x<size;x++) 
    for(y=0;y<size;y++)
      temp_board[y][x]=temp_board[x][y];
  // copy temp board back over board
  for(x=0;x<size;x++) 
    for(y=0;y<size;y++)
      board[x][y]=temp_board[y][x];
  return 0;
}

int board_rotate_180(int size,int **board)
{
  board_rotate_90(size,board);
  return board_rotate_90(size,board);
}

int board_rotate_270(int size,int **board)
{
  board_rotate_180(size,board);
  return board_rotate_90(size,board);
}

int tilt_board_right(int size,int **board)
{
  board_rotate_180(size,board);
  tilt_board_left(size,board);
  board_rotate_180(size,board);
  return 0;
}

int tilt_board_up(int size,int **board)
{
  board_rotate_90(size,board);
  tilt_board_left(size,board);
  board_rotate_90(size,board);
  return 0;
}

int tilt_board_down(int size,int **board)
{
  board_rotate_270(size,board);
  tilt_board_left(size,board);
  board_rotate_270(size,board);
  return 0;
}


