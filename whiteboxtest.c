#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "2048.h"


int main(int argc,char **argv)
{
	int e=0;
	
	whiteboxtest_lose();
	
	return e;
}


void whiteboxtest_lose() {
	//initialise input array
	int size = 4;
	int **input = board_create(size);
	int i, j, output;
	
	//begin testing
	printf("White Box Test Lose:\n");
	
	//TEST CASE
	printf("TEST CASE: tiles < size*size && random tiles\n");
	for(i = 0; i < size*size-1; i++)
		board_spawn_tile(size, input);
	printf("Input:\n");
	board_display(size, input);
	
	output = check_lose(size, input);
	if(!output) 
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is 0 but actual output is 1.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	
	//TEST CASE
	printf("TEST CASE: tiles < size*size && row equality\n");
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j ++)
			input[i][j] = (i+1)*(j+1);
	input[size-1][size-1] = 0;
	input[1][1] = input[2][1] = 512;
	tile_counter(size*size-1);
	printf("Input:\n");
	board_display(size, input);
	
	output = check_lose(size, input);
	if(!output) 
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is 0 but actual output is 1.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
		
	
	free(input);
	printf("\n");

}


void reset(int size, int **board)	//reset an array to all 0s
{
	int i, j;
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j++) 
			board[i][j] = 0;
}
