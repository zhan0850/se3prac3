#include <stdio.h>
#include "2048.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char **argv)
{
	// Randomise random unmber generator initial state.
	srandom(time(0));

	play();
	return 0;
}


void play() {
	//initialise the game board
	int board_size = 4;
	int **board = board_create(board_size);
	if (!board) {
		printf("failed to create board.\n");
		exit(0);
	}
	//generate 2 tiles at random locations
	board_spawn_tile(board_size, board);
	board_spawn_tile(board_size, board);
	
	//start playing
	while(1) {
		static int spawn = 0;	//for deciding whether or not to spawn a new tile depending on validity of last move
		static int has_checked_win = 0;	//winning is only checked once for 1 game
		
		board_display(board_size, board);
		
		/*
		 * check win
		 * this must be checked before check lose, in case win and lose happen at the same time
		 * the 2nd method (commented one) is not used because it uses a separate double loop to check, 
		 * while the 1st method checks for win at the same time when combining the tiles in tilt functions 
		 * so the 1st one is faster (although not so obvious with a board of size 4x4)
		 */
		if(!has_checked_win)
			if(spawn == 2) {
				has_checked_win = 1;
				
				printf("Congratulations!!! You win!!!\nContinue? (1/0)"); 
				int game = 0;
				scanf("%d", &game);
				
				if(!game) 
					break;
			}
/*		
		if(!has_checked_win) {
			int win = check_win(board_size, board);
			
			if(win) {
				has_checked_win = 1;
				
				printf("Congratulations!!! You win!!!\nContinue? (1/0)"); 
				int game = 0;
				scanf("%d", &game);
				
				if(!game) 
					break;
			}
		}
*/		
		
		//check lose
		//uses a separate double loop to check, because can't check for lose while tilting the board, because it should be checked after a new tile is spawned
		int dead = check_lose(board_size, board);
		if(dead) {
			printf("Game Over!!!\nTry again? (1/0)");
			int again = 0;
			scanf("%d", &again);
			if(again) {
				tile_counter(-tile_counter(0));
				free(board);
				play();
			}
			else
				break;		//break do-while to exit
		}
		
		//for one single move
		printf("Next move? "); 
		fflush(stdout);
		int action=read_input();
		switch(action) {
			case GO_LEFT:
				spawn = tilt_board_left(board_size, board);
				break;
	    		case GO_RIGHT:
				spawn = tilt_board_right(board_size, board);
				break;
			case GO_UP:
				spawn = tilt_board_up(board_size, board);
				break;
			case GO_DOWN:
				spawn = tilt_board_down(board_size,board);
				break;
			//case GO_NOWHERE:
				//break;
			case INVALID_INPUT:
			default:
				spawn = 0;
				printf("Invalid input. Type a, d, w or s to tilt board.\n");
				break;
		}
		
		if(spawn)	//keep spawning as long as the above move is valid
			board_spawn_tile(board_size, board);
		
	}
}


