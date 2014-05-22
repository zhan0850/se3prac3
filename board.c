#include <stdio.h>
#include <stdlib.h>
#include "2048.h"

int **board_create(int size)
{
	int i;
	// make sure size of board is sensible
	if (size<1||size>255) 
		return NULL;

	int **board=calloc(size,sizeof(int *));
	if (!board) 
		return NULL;
	for(i=0;i<size;i++) {
		board[i]=calloc(size,sizeof(int));
		if (!board[i]) 
			return NULL;
	}
	
	
//for test win
//board[size-1][size-1] = 1024;
//board[size-1][size-2] = 1024;

	return board;
}


int board_display(int size,int **board)
{
	// make sure size of board is sensible
	if (size<1||size>255) 
		return -1;

	//display the board
	int x,y;
	for(y=0;y<size;y++) {    
		for(x=0;x<size;x++) {
			if (board[x][y]) 
				printf("[% 5d]",board[x][y]);
			else 
				printf("[     ]");
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
		
	tile_counter(1);
	
}


int tile_counter(int adder) {
	static int count = 0;

	count += adder;
	
	return count;
}


int check_lose(int size, int **board)
{	
	int dead = 0;
	
	int tiles = tile_counter(0); 
	//printf("No. of tiles %d\n", tiles);
	
	if(tiles == size*size) {	//game is over only if board is full
		dead = 1;
		
		int col, row;
		for(col = 0; col < size; col++) {		//checking
			for(row = 0; row < size; row++) {
				if(col < size-1) {
					if(board[col][row] == board[col+1][row]) {
						dead = 0;
						break;
					}
				}
				
				if(row < size-1) {
					if(board[col][row] == board[col][row+1]) {
						dead = 0;
						break;
					}
				}
			}
			
			if(!dead) 
				break;
		}
	}
	
	return dead;
}


int check_win(int size, int **board)
{
	int i, j;
	
	for(i = 0; i < size; i++) 
		for(j = 0; j < size; j++)
			if(board[i][j] == 2048)
				return 1;
	
	return 0;
}