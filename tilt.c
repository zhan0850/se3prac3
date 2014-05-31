#include <stdio.h>
#include <stdlib.h>
#include "2048.h"

/***************************************
int tilt_line_left(int length,int *line)
{
  // make sure vector length is sensible
  if (length<1||length>255) return -1;

  // slide tiles to the left
  

  // combine tiles as required

  return 0;
}
****************************************/

int tilt_board_left(int size,int **board) {
	// make sure vector length is sensible
	if (size<1||size>255)
		return -1;
	
	//for deciding whether this move is valid
	//if so, generate a new tile, else, nothing will happen
	int spawn = 0;
	
	//keeping track of if this move generates a tile 2048
	int win = 0;
	
	int row, col, x, y;
	for(row = 0; row < size; row++) {
		for(col = 0; col < size; col++) {
			//get the 1st tile
			if(board[col][row]) {
				for(x = col+1; x < size; x++) {
					//get the 2nd tile
					if(board[x][row]) {
						//combine tiles if equal value
						if(board[x][row] == board[col][row]) {
							board[col][row] += board[x][row];
							board[x][row] = 0;
							
							spawn = 1;
							tile_counter(-1);
							
							if(board[col][row] == 2048)
								win = 1;
						}
						//no need to get the 3rd tile
						break;
					}
				}
				
				//move to the furthest empty location
				for(y = col-1; y >= 0; y--) {
					//find the 1st non-empty location
					if(board[y][row]) {
						//move next to it
						if(y+1 != col) {
							board[y+1][row] = board[col][row];
							board[col][row] = 0;
							
							spawn = 1;
						}
						break;
					}
					
					//move to the end if all empty
					if(y == 0 && !board[y][row]) {
						board[y][row] = board[col][row];
						board[col][row] = 0;
						
						spawn = 1;
					}
				}
			
			} //if board[col]
		} //for col
	} //for row
	
	if(win)
		spawn = 2;
	
	return spawn;
}


int tilt_board_right(int size,int **board) {
	if (size<1||size>255) 
		return -1;
	
	int spawn = 0;
	int win = 0;
	
	int row, col, x, y;
	for(row = 0; row < size; row++) {
		for(col = size-1; col >= 0; col--) {
			if(board[col][row]) {
				for(x = col-1; x >= 0; x--) {
					if(board[x][row]) {
						if(board[x][row] == board[col][row]) {
							board[col][row] += board[x][row];
							board[x][row] = 0;
							
							spawn = 1;
							tile_counter(-1);
							
							if(board[col][row] == 2048)
								win = 1;
						}
						break;
					} 
				}
				
				for(y = col+1; y < size; y++) {
					if(board[y][row]) {
						if(y-1 != col) {
							board[y-1][row] = board[col][row];
							board[col][row] = 0;
							
							spawn = 1;
						}
						break;
					}
					
					if(y == size-1 && !board[y][row]) {
						board[y][row] = board[col][row];
						board[col][row] = 0;
						
						spawn = 1;
					}
				}
			
			}
		}
	}
	
	if(win)
		spawn = 2;
	
	return spawn;
}


int tilt_board_up(int size,int **board) {
	if (size<1||size>255)
		return -1;
	
	int spawn = 0;
	int win = 0;
	
	int row, col, x, y;
	for(col = 0; col < size; col++) {
		for(row = 0; row < size; row++) {
			if(board[col][row]) {
				for(x = row+1; x < size; x++) {
					if(board[col][x]) {
						if(board[col][x] == board[col][row]) {
							board[col][row] += board[col][x];
							board[col][x] = 0;
							
							spawn = 1;
							tile_counter(-1);
							
							if(board[col][row] == 2048)
								win = 1;
						}
						break;
					}
				}
				
				for(y = row-1; y >= 0; y--) {
					if(board[col][y]) {
						if(y+1 != row) {
							board[col][y+1] = board[col][row];
							board[col][row] = 0;
							
							spawn = 1;
						}
						break;
					}
					
					if(y == 0 && !board[col][y]) {
						board[col][y] = board[col][row];
						board[col][row] = 0;
						
						spawn = 1;
					}
				}
			
			}
		}
	}
	
	if(win)
		spawn = 2;
	
	return spawn;
}


int tilt_board_down(int size,int **board) {
	if (size<1||size>255)
		return -1;
	
	int spawn = 0;
	int win = 0;
	
	int row, col, x, y;
	for(col = 0; col < size; col++) {
		for(row = size-1; row >= 0; row--) {
			if(board[col][row]) {
				for(x = row-1; x >= 0; x--) {
					if(board[col][x]) {
						if(board[col][x] == board[col][row]) {
							board[col][row] += board[col][x];
							board[col][x] = 0;
							
							spawn = 1;
							tile_counter(-1);
							
							if(board[col][row] == 2048)
								win = 1;
						}
						break;
					}
				}
				
				for(y = row+1; y < size; y++) {
					if(board[col][y]) {
						if(y-1 != row) {
							board[col][y-1] = board[col][row];
							board[col][row] = 0;
							
							spawn = 1;
						}
						break;
					}
					
					if(y == size-1 && !board[col][y]) {
						board[col][y] = board[col][row];
						board[col][row] = 0;
						
						spawn = 1;
					}
				}
			
			}
		}
	} 
	
	if(win)
		spawn = 2;
	
	return spawn;
}

