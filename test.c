#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "2048.h"


int main(int argc,char **argv)
{
	int e=0;
	
	test_tilt_left();
	test_tilt_right();
	test_tilt_up();
	test_tilt_down();
	
	test_board_spawn_tile();
	test_tile_counter();
	
	test_check_lose();
	test_check_win();
	
	return e;
}


void test_tilt_left()
{
	//initialise input array and output array
	int size = 4;
	int **input = board_create(size);
	int **output = board_create(size);
	int i, j;
	
	//begin testing
	printf("Tilt Left Tests:\n");
	
	//empty board
	tilt_test("Test Case: empty board is empty after shift ", tilt_board_left, size, input, output);
	reset(size, input);
	reset(size, output);
		
	//values on left, in middle, and on right
	for(i = 0; i < size; i++) {
		input[i][i] = 2;
		output[0][i] = 2;
	}
	tilt_test("Test Case: values on left, in middle, and on right move to left be after shift ", tilt_board_left, size, input, output);
	reset(size, input);
	reset(size, output);
	
	//combining tiles
	for(i = 0; i < size; i++) {
		input[i][0] = output[i][0] = (i+1)*2;
		for(j = 1; j < size; j++) {
			input[i][j] = 2;
			output[0][j] = output[1][j] = 4;
		}
	}
	input[0][2] = input[0][3] = input[1][3] = 4;
	input[1][2] = 0;
	output[0][3] = 8;
	tilt_test("Test Case: same values combine, distinct values don't ", tilt_board_left, size, input, output);
	reset(size, input);
	reset(size, output);
	
	//done testing, deallocate memory
	free(input);
	free(output);
	printf("\n");
}


void test_tilt_right()
{
	//initialise input array and output array
	int size = 4;
	int **input = board_create(size);
	int **output = board_create(size);
	int i, j;
	
	//begin testing
	printf("Tilt Right Tests:\n");
	
	//empty board
	tilt_test("Test Case: empty board is empty after shift ", tilt_board_right, size, input, output);
	reset(size, input);
	reset(size, output);
		
	//values on left, in middle, and on right
	for(i = 0; i < size; i++) {
		input[i][i] = 2;
		output[3][i] = 2;
	}
	tilt_test("Test Case: values on left, in middle, and on right move to right be after shift ", tilt_board_right, size, input, output);
	reset(size, input);
	reset(size, output);
	
	//combining tiles
	for(i = 0; i < size; i++) {
		input[i][0] = output[i][0] = (i+1)*2;
		for(j = 1; j < size; j++) {
			input[i][j] = 2;
			output[2][j] = output[3][j] = 4;
		}
	}
	input[0][2] = input[0][3] = input[1][3] = 4;
	input[1][2] = 0;
	output[2][3] = 8;
	tilt_test("Test Case: same values combine, distinct values don't ", tilt_board_right, size, input, output);
	reset(size, input);
	reset(size, output);
	
	//done testing, deallocate memory
	free(input);
	free(output);
	printf("\n");
}


void test_tilt_up()
{
	//initialise input array and output array
	int size = 4;
	int **input = board_create(size);
	int **output = board_create(size);
	int i, j;
	
	//begin testing
	printf("Tilt Up Tests:\n");
	
	//empty board
	tilt_test("Test Case: empty board is empty after shift ", tilt_board_up, size, input, output);
	reset(size, input);
	reset(size, output);
		
	//values on left, in middle, and on right
	for(i = 0; i < size; i++) {
		input[i][i] = 2;
		output[i][0] = 2;
	}
	tilt_test("Test Case: values on left, in middle, and on right move to top be after shift ", tilt_board_up, size, input, output);
	reset(size, input);
	reset(size, output);
	
	//combining tiles
	for(i = 0; i < size; i++) {
		input[0][i] = output[0][i] = (i+1)*2;
		for(j = 1; j < size; j++) {
			input[j][i] = 2;
			output[j][0] = output[j][1] = 4;
		}
	}
	input[2][0] = input[3][0] = input[3][1] = 4;
	input[2][1] = 0;
	output[3][0] = 8;
	tilt_test("Test Case: same values combine, distinct values don't ", tilt_board_up, size, input, output);
	reset(size, input);
	reset(size, output);
	
	//done testing, deallocate memory
	free(input);
	free(output);
	printf("\n");
}


void test_tilt_down()
{
	//initialise input array and output array
	int size = 4;
	int **input = board_create(size);
	int **output = board_create(size);
	int i, j;
	
	//begin testing
	printf("Tilt Down Tests:\n");
	
	//empty board
	tilt_test("Test Case: empty board is empty after shift ", tilt_board_down, size, input, output);
	reset(size, input);
	reset(size, output);
	
	//values on left, in middle, and on right
	for(i = 0; i < size; i++) {
		input[i][i] = 2;
		output[i][3] = 2;
	}
	tilt_test("Test Case: values on left, in middle, and on right move to bottom be after shift ", tilt_board_down, size, input, output);
	reset(size, input);
	reset(size, output);
	
	//combining tiles
	for(i = 0; i < size; i++) {
		input[0][i] = output[0][i] = (i+1)*2;
		for(j = 1; j < size; j++) {
			input[j][i] = 2;
			output[j][2] = output[j][3] = 4;
		}
	}
	input[2][0] = input[3][0] = input[3][1] = 4;
	input[2][1] = 0;
	output[3][2] = 8;
	tilt_test("Test Case: same values combine, distinct values don't ", tilt_board_down, size, input, output);
	reset(size, input);
	reset(size, output);
	
	//done testing, deallocate memory
	free(input);
	free(output);
	printf("\n");
}


void tilt_test(char *msg, int func(int, int**), int size, int **input, int **output)
{	
	if(msg)
		printf("%s\n", msg);
	fflush(stdout);
	
	printf("Input:\n");
	board_display(size, input);
	
	func(size, input);
	
	int i, j;
	for(i = 0; i < size; i++) 
		for(j = 0; j < size; j++)
			if(input[i][j] != output[i][j]) {
				printf("FAILED!\nExpected Output:\n");
				board_display(size, output);
				printf("Actual Output:\n");
				board_display(size, input);
				return;
			}
	
	printf("PASSED. Actual output matches expected output.\n");
	board_display(size, output);
}


void test_board_spawn_tile()
{
	//begin testing
	printf("Test Spawn Tile:\n");
	
	printf("Test Case: value should be 2 or 4\n");
	//initialise input array
	int size = 1;
	int **input = board_create(size);
	
	board_spawn_tile(size, input);
	
	if(input[0][0] == 2 || input[0][0] == 4)
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is 2 or 4, but actual output is %d.\n", input[0][0]);
	
	//reset counter, deallocate memory
	tile_counter(-tile_counter(0));
	free(input);
	
	printf("Test Case: location should be an empty spot\n");
	//initialise input array
	size = 2;
	input = board_create(size);
	input[0][0] = input[1][1] = 8;
	
	board_spawn_tile(size, input);
	
	if(input[0][0] == 8 && input[1][1] == 8)
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is 2 or 4, but actual output is %d.\n", input[0][0]);
	
	//reset counter, deallocate memory
	tile_counter(-tile_counter(0));
	free(input);
	
	printf("\n");
}


void test_tile_counter()
{
	//initialise board
	int size = 4;
	int **board = board_create(size);
	int i, output, expected;
	
	//begin testing
	printf("Test Tile Counter:\n");
	
	//test case
	printf("Test Case: test initial value, expected output is 0\n");
	output = tile_counter(0);
	expected = 0;
	if(output == expected)
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is %d, but actual output is %d.\n", expected, output);
	
	//test case
	printf("Test Case: test addition, expected output is 1\n");
	output = tile_counter(1);
	expected = 1;
	if(output == expected)
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is %d, but actual output is %d.\n", expected, output);
	tile_counter(-tile_counter(0));
	
	//test case
	printf("Test Case: test addition in board_spawn_tile function, expected output is 10\n");
	for(i = 0; i < 10; i++) 
		board_spawn_tile(size, board);
	output = tile_counter(0);
	expected = 10;
	if(output == expected)
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is %d, but actual output is %d.\n", expected, output);
	reset(size, board);
	
	//test case
	printf("Test Case: test substraction when reset game, expected output is 0\n");
	output = tile_counter(-tile_counter(0));
	expected = 0;
	if(output == expected)
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is %d, but actual output is %d.\n", expected, output);
	
	//test case
	printf("Test Case: test substraction in tilt_board_left function, expected output is 1\n");
	board[0][0] = board[1][0] = 2;
	tile_counter(2);
	tilt_board_left(size, board);
	output = tile_counter(0);
	expected = 1;
	if(output == expected)
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is %d, but actual output is %d.\n", expected, output);
	reset(size, board);
	tile_counter(-tile_counter(0));
	
	//test case
	printf("Test Case: test substraction in tilt_board_right function, expected output is 1\n");
	board[0][0] = board[1][0] = 2;
	tile_counter(2);
	tilt_board_right(size, board);
	output = tile_counter(0);
	expected = 1;
	if(output == expected)
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is %d, but actual output is %d.\n", expected, output);
	reset(size, board);
	tile_counter(-tile_counter(0));
	
	//test case
	printf("Test Case: test substraction in tilt_board_up function, expected output is 1\n");
	board[0][0] = board[0][1] = 2;
	tile_counter(2);
	tilt_board_up(size, board);
	output = tile_counter(0);
	expected = 1;
	if(output == expected)
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is %d, but actual output is %d.\n", expected, output);
	reset(size, board);
	tile_counter(-tile_counter(0));
	
	//test case
	printf("Test Case: test substraction in tilt_board_down function, expected output is 1\n");
	board[0][0] = board[0][1] = 2;
	tile_counter(2);
	tilt_board_down(size, board);
	output = tile_counter(0);
	expected = 1;
	if(output == expected)
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is %d, but actual output is %d.\n", expected, output);
	reset(size, board);
	tile_counter(-tile_counter(0));
	
	//done testing, deallocate memory
	free(board);
	printf("\n");
}


void test_check_lose()
{
	//initialise input array
	int size = 4;
	int **input = board_create(size);
	int i, j, output;
	
	//begin testing
	printf("Test Lose:\n");
	
	//board not full
	printf("Test Case: board is not full, game is not over\n");
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
	
	//board full, same value in a row
	printf("Test Case: board full, same value in a row consecutively, game not over\n");
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j ++)
			input[i][j] = (i+1)*(j+1);
	tile_counter(size*size);
	input[1][2] = input[2][2];
	printf("Input:\n");
	board_display(size, input);
	
	output = check_lose(size, input);
	if(!output) 
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is 0 but actual output is 1.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	
	//board full, same value in a column
	printf("Test Case: board full, same value in a column consecutively, game not over\n");
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j ++)
			input[i][j] = (i+1)*(j+1);
	tile_counter(size*size);
	input[2][1] = input[2][2];
	printf("Input:\n");
	board_display(size, input);
	
	output = check_lose(size, input);
	if(!output) 
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is 0 but actual output is 1.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	
	//board full, no same value
	printf("Test Case: board full, no same value, game over\n");
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j ++)
			input[i][j] = (i+1)*(j+1);
	tile_counter(size*size);
	printf("Input:\n");
	board_display(size, input);
	
	output = check_lose(size, input);
	if(output) 
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is 1 but actual output is 0.\n");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	
	//done testing, deallocate memory
	free(input);
	printf("\n");
}


void test_check_win()
{
	//the game does not use a separate function to check win, win is checked in tilt functions, see files main.c & tilt.c for more details
	//initialise input array
	int size = 4;
	int **input = board_create(size);
	int i, output;
	
	//begin testing
	printf("Test Win:\n");
	
	//not win
	printf("Not win test cases\n");
	
	//tilt left
	for(i = 0; i < size*size; i++)
		board_spawn_tile(size, input);
	
	printf("Test Case: not win after tilt left\nOriginal input:\n");
	board_display(size, input);
	
	printf("Input after tilt left\n");
	output = tilt_board_left(size, input);
	board_display(size, input);
	
	printf("Possible outputs:\n0 - invalid move (0.00000086 chance (see board_spawn_tile function), so you win a big prize if you fail the test)\n1 - valid but not win (expected output)\n2 - win (you fail the test, but this is not gonna happen)\n");
	if(output == 1) 
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("Failed. Expected output is 1, but actual output is %d.\n", output);
	if(output == 0)
		printf("Although you failed the test, but there's only 0.00000086 chance you get a 0 in this test. Congrats!");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	
	//tilt right
	for(i = 0; i < size*size; i++)
		board_spawn_tile(size, input);
	
	printf("Test Case: not win after tilt right\nOriginal input:\n");
	board_display(size, input);
	
	printf("Input after tilt right\n");
	output = tilt_board_right(size, input);
	board_display(size, input);
	
	printf("Possible outputs:\n0 - invalid move (0.00000086 chance (see board_spawn_tile function), so you win a big prize if you fail the test)\n1 - valid but not win (expected output)\n2 - win (you fail the test, but this is not gonna happen)\n");
	if(output == 1) 
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("Failed. Expected output is 1, but actual output is %d.\n", output);
	if(output == 0)
		printf("Although you failed the test, but there's only 0.00000086 chance you get a 0 in this test. Congrats!");
	
	reset(size, input);
	tile_counter(-tile_counter(0));
	
	//tilt up
	for(i = 0; i < size*size; i++)
		board_spawn_tile(size, input);
	
	printf("Test Case: not win after tilt up\nOriginal input:\n");
	board_display(size, input);
	
	printf("Input after tilt up\n");
	output = tilt_board_up(size, input);
	board_display(size, input);
	
	printf("Possible outputs:\n0 - invalid move (0.00000086 chance (see board_spawn_tile function), so you win a big prize if you fail the test)\n1 - valid but not win (expected output)\n2 - win (you fail the test, but this is not gonna happen)\n");
	if(output == 1) 
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("Failed. Expected output is 1, but actual output is %d.\n", output);
	if(output == 0)
		printf("Although you failed the test, but there's only 0.00000086 chance you get a 0 in this test. Congrats!");
	
	reset(size, input);
	tile_counter(-tile_counter(0));

	//tilt down
	for(i = 0; i < size*size; i++)
		board_spawn_tile(size, input);
	
	printf("Test Case: not win after tilt down\nOriginal input:\n");
	board_display(size, input);
	
	printf("Input after tilt down\n");
	output = tilt_board_down(size, input);
	board_display(size, input);
	
	printf("Possible outputs:\n0 - invalid move (0.00000086 chance (see board_spawn_tile function), so you win a big prize if you fail the test)\n1 - valid but not win (expected output)\n2 - win (you fail the test, but this is not gonna happen)\n");
	if(output == 1) 
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("Failed. Expected output is 1, but actual output is %d.\n", output);
	if(output == 0)
		printf("Although you failed the test, but there's only 0.00000086 chance you get a 0 in this test. Congrats!");
	
	reset(size, input);
	tile_counter(-tile_counter(0));

	//win
	printf("Win test cases\n");
	
	//tilt left
	input[0][0] = input[1][0] = 1024;
	
	printf("Test Case: win after tilt left\nOriginal input:\n");
	board_display(size, input);
	
	printf("Input after tilt left\n");
	output = tilt_board_left(size, input);
	board_display(size, input);
	
	printf("Possible outputs:\n0 - invalid move (actually not possible since the values are set)\n1 - valid but not win (you fail the test)\n2 - win (expected output)\n");
	if(output == 2) 
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("Failed. Expected output is 2, but actual output is %d.\n", output);
		
	reset(size, input);
	
	//tilt right
	input[0][0] = input[1][0] = 1024;
	
	printf("Test Case: win after tilt right\nOriginal input:\n");
	board_display(size, input);
	
	printf("Input after tilt right\n");
	output = tilt_board_right(size, input);
	board_display(size, input);
	
	printf("Possible outputs:\n0 - invalid move (actually not possible since the values are set)\n1 - valid but not win (you fail the test)\n2 - win (expected output)\n");
	if(output == 2) 
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("Failed. Expected output is 2, but actual output is %d.\n", output);
	
	reset(size, input);
	
	//tilt up
	input[0][0] = input[0][1] = 1024;
	
	printf("Test Case: win after tilt up\nOriginal input:\n");
	board_display(size, input);
	
	printf("Input after tilt up\n");
	output = tilt_board_up(size, input);
	board_display(size, input);
	
	printf("Possible outputs:\n0 - invalid move (actually not possible since the values are set)\n1 - valid but not win (you fail the test)\n2 - win (expected output)\n");
	if(output == 2) 
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("Failed. Expected output is 2, but actual output is %d.\n", output);
	
	reset(size, input);
	
	//tilt down
	input[0][0] = input[0][1] = 1024;
	
	printf("Test Case: win after tilt down\nOriginal input:\n");
	board_display(size, input);
	
	printf("Input after tilt down\n");
	output = tilt_board_down(size, input);
	board_display(size, input);
	
	printf("Possible outputs:\n0 - invalid move (actually not possible since the values are set)\n1 - valid but not win (you fail the test)\n2 - win (expected output)\n");
	if(output == 2) 
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("Failed. Expected output is 2, but actual output is %d.\n", output);
	
	reset(size, input);
	
	//done testing, deallocate memory
	free(input);
	
}


void reset(int size, int **board)	//reset an array to all 0s
{
	int i, j;
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j++) 
			board[i][j] = 0;
}


/*********************************************************************************
int ttl_vector(int i1,int i2,int i3,int i4,char *msg,
               int o1,int o2,int o3,int o4)
{
  return line_vector_test(i1,i2,i3,i4,msg,o1,o2,o3,o4,tilt_line_left);
}


int line_vector_test(int i1,int i2,int i3,int i4,char *msg,
                int o1,int o2,int o3,int o4, int (*func)(int,int *))
{
  int list[4]={i1,i2,i3,i4};
  if (msg) printf("%s - ",msg); 
  else {
    printf("Tilting {%d,%d,%d,%d} left yields {%d,%d,%d,%d} - ",
             i1,i2,i3,i4,o1,o2,o3,o4);
  }
  fflush(stdout);
  func(4,list);
  if ((list[0]!=o1)||(list[1]!=o2)||(list[2]!=o3)||(list[3]!=o4))
    {
      printf("FAILED: {%d,%d,%d,%d} became {%d,%d,%d,%d} instead of"
             " {%d,%d,%d,%d}\n",
             i1,i2,i3,i4,list[0],list[1],list[2],list[3],
             o1,o2,o3,o4);
      return -1;
    } 
  printf("PASSED.\n");
  return 0;
  
}
*/