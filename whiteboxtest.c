#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "2048.h"


int main(int argc,char **argv)
{
	int e=0;
	
	printf("Begin White Box Testing\n\n");
	
	whiteboxtest_lose();
	whiteboxtest_win();
	
	printf("End White Box Testing\n");
	
	return e;
}


void whiteboxtest_lose() {
	//initialise input array
	int size = 4;
	int **input = board_create(size);
	int i, j, output;
	
	//begin testing
	printf("Test Lose:\n");
	
	//TEST CASE
	printf("TEST CASE: tiles < size*size && random inputs, game not lost\n");
	for(i = 0; i < size*size-1; i++)
		board_spawn_tile(size, input);
	printf("Input:\n");
	board_display(size, input);
	
	output = check_lose(size, input);
	if(!output) 
		printf("Output: not lost\nPASSED. Actual output matches expected output.\n");
	else
		printf("Output: game over\nFAILED! Expected output is 0 but actual output is 1.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	printf("\n");
	
	//TEST CASE
	printf("TEST CASE: tiles < size*size && row equality, game not lost\n");
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
		printf("Output: not lost\nPASSED. Actual output matches expected output.\n");
	else
		printf("Output: game over\nFAILED! Expected output is 0 but actual output is 1.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	printf("\n");
	
	//TEST CASE
	printf("TEST CASE: tiles < size*size && column equality, game not lost\n");
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j ++)
			input[i][j] = (i+1)*(j+1);
	input[size-1][size-1] = 0;
	input[2][1] = input[2][2] = 512;
	tile_counter(size*size-1);
	printf("Input:\n");
	board_display(size, input);
	
	output = check_lose(size, input);
	if(!output) 
		printf("Output: not lost\nPASSED. Actual output matches expected output.\n");
	else
		printf("Output: game over\nFAILED! Expected output is 0 but actual output is 1.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	printf("\n");
	
	//TEST CASE
	printf("TEST CASE: tiles < size*size && board wide inequality, game not lost\n");
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j ++)
			input[i][j] = (i+1)*(j+1);
	input[size-1][size-1] = 0;
	tile_counter(size*size-1);
	printf("Input:\n");
	board_display(size, input);
	
	output = check_lose(size, input);
	if(!output) 
		printf("Output: not lost\nPASSED. Actual output matches expected output.\n");
	else
		printf("Output: game over\nFAILED! Expected output is 0 but actual output is 1.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	printf("\n");
	
	//TEST CASE
	printf("TEST CASE: tiles == size*size && random inputs, game not lost\n");
	for(i = 0; i < size*size; i++)
		board_spawn_tile(size, input);
	printf("Input:\n");
	board_display(size, input);
	
	output = check_lose(size, input);
	if(!output) 
		printf("Output: not lost\nPASSED. Actual output matches expected output.\n");
	else
		printf("Output: game over\nFAILED! Expected output is 0 but actual output is 1.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	printf("\n");
	
	//TEST CASE
	printf("TEST CASE: tiles == size*size && row equality, game not lost\n");
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j ++)
			input[i][j] = (i+1)*(j+1);
	input[1][1] = input[2][1] = 512;
	tile_counter(size*size);
	printf("Input:\n");
	board_display(size, input);
	
	output = check_lose(size, input);
	if(!output) 
		printf("Output: not lost\nPASSED. Actual output matches expected output.\n");
	else
		printf("Output: game over\nFAILED! Expected output is 0 but actual output is 1.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	printf("\n");
	
	//TEST CASE
	printf("TEST CASE: tiles == size*size && column equality, game not lost\n");
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j ++)
			input[i][j] = (i+1)*(j+1);
	input[2][1] = input[2][2] = 512;
	tile_counter(size*size);
	printf("Input:\n");
	board_display(size, input);
	
	output = check_lose(size, input);
	if(!output) 
		printf("Output: not lost\nPASSED. Actual output matches expected output.\n");
	else
		printf("Output: game over\nFAILED! Expected output is 0 but actual output is 1.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	printf("\n");
	
	//TEST CASE
	printf("TEST CASE: tiles == size*size && board wide inequality, game over\n");
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j ++)
			input[i][j] = (i+1)*(j+1);
	tile_counter(size*size);
	printf("Input:\n");
	board_display(size, input);
	
	output = check_lose(size, input);
	if(output) 
		printf("Output: game over\nPASSED. Actual output matches expected output.\n");
	else
		printf("Output: not lost\nFAILED! Expected output is 1 but actual output is 0.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	printf("\n");

	free(input);
	printf("\n");
}


void whiteboxtest_win() {
	//initialise input array
	int size = 4;
	int **input = board_create(size);
	int i, j, output;
	
	//begin testing
	printf("Test Win:\n");
	
	//TEST CASE
	printf("TEST CASE: tilt_left, no tiles combined, no 2048, not won\n");
	for(i = size-2; i < size; i++)
		for(j = 0; j < size; j ++) {
			input[i][j] = (i+1)*(j+1);
			tile_counter(1);
	}
	printf("Input:\n");
	board_display(size, input);
	
	output = tilt_board_left(size, input);
	printf("Output:\n");
	board_display(size, input);
	
	if(output != 2) 
		printf("Not won\nPASSED. Actual output matches expected output.\n");
	else
		printf("Won\nFAILED! Expected output is 0 or 1 but actual output is 2.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	printf("\n");
	
	//TEST CASE
	printf("TEST CASE: tilt_left, tiles combined, no 2048, not won\n");
	for(i = 0; i < size; i++) {
		input[size-2][i] = input[size-1][i] = (i+1)*2;
		tile_counter(2);
	}
	printf("Input:\n");
	board_display(size, input);
	
	output = tilt_board_left(size, input);
	printf("Output:\n");
	board_display(size, input);
	
	if(output != 2) 
		printf("Not won\nPASSED. Actual output matches expected output.\n");
	else
		printf("Won\nFAILED! Expected output is 0 or 1 but actual output is 2.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	printf("\n");
	
	//TEST CASE
	printf("TEST CASE: tilt_left, no tiles combined, has 2048, not won\n");
	for(i = size-2; i < size; i++)
		for(j = 0; j < size; j ++) {
			input[i][j] = (i+1)*(j+1);
			tile_counter(1);
	}
	input[i-1][j-1] = 2048;
	printf("Input:\n");
	board_display(size, input);
	
	output = tilt_board_left(size, input);
	printf("Output:\n");
	board_display(size, input);
	
	if(output != 2) 
		printf("Not won\nPASSED. Actual output matches expected output.\n");
	else
		printf("Won\nFAILED! Expected output is 0 or 1 but actual output is 2.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	printf("\n");
	
	//TEST CASE
	printf("TEST CASE: tilt_left, tiles combined, become 2048, won\n");
	for(i = size-2; i < size; i++)
		for(j = 0; j < size; j ++) {
			input[i][j] = (i+1)*(j+1);
			tile_counter(1);
	}
	input[i-1][j-1] = input[i-2][j-1] = 1024;
	printf("Input:\n");
	board_display(size, input);
	
	output = tilt_board_left(size, input);
	printf("Output:\n");
	board_display(size, input);
	
	if(output == 2) 
		printf("Won\nPASSED. Actual output matches expected output.\n");
	else
		printf("Not won\nFAILED! Expected output is 0 or 1 but actual output is 2.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	printf("\n");
	
	//TEST CASE
	printf("TEST CASE: tilt_right: no tiles combined, no 2048, not won\n");
	
	//adfasdf
	
	//TEST CASE
	printf("TEST CASE: tilt_right: tiles combined, no 2048, not won\n");
	
	
	
	//TEST CASE
	printf("TEST CASE: tilt_right: no tiles combined, has 2048, not won\n");
	
	
	
	//TEST CASE
	printf("TEST CASE: tilt_right: tiles combined, become 2048, won\n");
	
	
	
	//TEST CASE
	printf("TEST CASE: tilt_up: no tiles combined, no 2048, not won\n");
	
	
	
	//TEST CASE
	printf("TEST CASE: tilt_up: tiles combined, no 2048, not won\n");
	
	
	
	//TEST CASE
	printf("TEST CASE: tilt_up: no tiles combined, has 2048, not won\n");
	
	
	
	//TEST CASE
	printf("TEST CASE: tilt_up: tiles combined, become 2048, won\n");
	
	
	
	//TEST CASE
	printf("TEST CASE: tilt_down: no tiles combined, no 2048, not won\n");
	
	
	
	//TEST CASE
	printf("TEST CASE: tilt_down: tiles combined, no 2048, not won\n");
	
	
	
	//TEST CASE
	printf("TEST CASE: tilt_down: no tiles combined, has 2048, not won\n");
	
	
	
	//TEST CASE
	printf("TEST CASE: tilt_down: tiles combined, become 2048, won\n");
	
	
	
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
