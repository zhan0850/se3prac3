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
	
}


void test_tilt_up()
{
	
}


void test_tilt_down()
{
	
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
	//initialise input array
	int size = 1;
	int **input = board_create(size);
	
	//begin testing
	printf("Test Spawn Tile:\n");
	
	board_spawn_tile(size, input);
	
	if(input[0][0] == 2 || input[0][0] == 4)
		printf("PASSED. Actual output matches expected output.\n");
	else
		printf("FAILED! Expected output is 2 or 4, but actual output is %d.\n", input[0][0]);
	
	//done testing, reset counter, deallocate memory
	tile_counter(-tile_counter(0));
	free(input);
	printf("\n");
}


void test_tile_counter()
{
	//
}


void test_check_lose()
{
	
}


void test_check_win()
{
	
	
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