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
	free(input);
	printf("\n");
}


void test_tile_counter()
{
	
}


void test_check_lose()
{
	
}


void test_check_win()
{
	
	
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