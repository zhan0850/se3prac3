#include <stdio.h>
#include "2048.h"

#include "tilt.c"
#include "board.c"

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

int board_vector_test(int i1,int i2,int i3,int i4,char *msg,
		      int o1,int o2,int o3,int o4, int (*func)(int,int **))
{
  int **board=alloca(2*sizeof(int*));
  board[0]=alloca(sizeof(int)*2);
  board[1]=alloca(sizeof(int)*2);
  board[0][0]=i1; board[1][0]=i2; board[0][1]=i3; board[1][1]=i4;

  if (msg) printf("%s - ",msg); 
  else {
    printf("Board operation on {{%d,%d},{%d,%d}} yields {{%d,%d},{%d,%d}} - ",
	     i1,i2,i3,i4,o1,o2,o3,o4);
  }
  fflush(stdout);
  func(2,board);
  if ((board[0][0]!=o1)||(board[1][0]!=o2)
      ||(board[0][1]!=o3)||(board[1][1]!=o4))
    {
      printf("FAILED: {{%d,%d},{%d,%d}} became {{%d,%d},{%d,%d}} instead of"
	     " {{%d,%d},{%d,%d}}\n",
	     i1,i2,i3,i4,
	     board[0][0],board[1][0],board[0][1],board[1][1],
	     o1,o2,o3,o4);
      return -1;
    } 
  printf("PASSED.\n");
  return 0;
}

int board3_vector_test(int i1,int i2,int i3,int i4,int i5,
		       int i6,int i7,int i8,int i9,char *msg,
		       int o1,int o2,int o3,int o4,int o5,
		       int o6,int o7,int o8,int o9,
		       int (*func)(int,int **))
{
  int **board=alloca(3*sizeof(int*));
  board[0]=alloca(sizeof(int)*3);
  board[1]=alloca(sizeof(int)*3);
  board[2]=alloca(sizeof(int)*3);
  board[0][0]=i1; board[1][0]=i2; board[2][0]=i3;
  board[0][1]=i4; board[1][1]=i5; board[2][1]=i6;
  board[0][2]=i7; board[1][2]=i8; board[2][2]=i9;

  if (msg) printf("%s - ",msg); 
  else {
    printf("Board operation on {{%d,%d,%d},...} yields {{%d,%d,%d}...} - ",
	     i1,i2,i3,o1,o2,o3);
  }
  fflush(stdout);
  func(3,board);
  if (
      (board[0][0]!=o1)||(board[1][0]!=o2)||(board[2][0]!=o3)||
      (board[0][1]!=o4)||(board[1][1]!=o5)||(board[2][1]!=o6)||
      (board[0][2]!=o7)||(board[1][2]!=o8)||(board[2][2]!=o9)
      )
    {
      printf("FAILED: {{%d,%d,%d},{%d,%d,%d},{%d,%d,%d}} became {{%d,%d,%d},{%d,%d,%d},{%d,%d,%d}} instead of"
	     " {{%d,%d,%d},{%d,%d,%d},{%d,%d,%d}}\n",
	     i1,i2,i3,i4,i5,i6,i7,i8,i9,
	     board[0][0],board[1][0],board[2][0],
	     board[0][1],board[1][1],board[2][1],
	     board[0][2],board[1][2],board[2][2],
	     o1,o2,o3,o4,o5,o6,o7,o8,o9);
      return -1;
    } 
  printf("PASSED.\n");
  return 0;
}

int board4_vector_test(int i1,int i2,int i3,int i4,int i5,
		       int i6,int i7,int i8,int i9,int i10,
		       int i11,int i12,int i13,int i14,int i15,int i16,
		       char *msg,
		       int o1,int o2,int o3,int o4,int o5,
		       int o6,int o7,int o8,int o9,int o10,
		       int o11,int o12,int o13,int o14,int o15,int o16,
		       int (*func)(int,int **))
{
  int **board=alloca(4*sizeof(int*));
  board[0]=alloca(sizeof(int)*4);
  board[1]=alloca(sizeof(int)*4);
  board[2]=alloca(sizeof(int)*4);
  board[3]=alloca(sizeof(int)*4);
  board[0][0]=i1; board[1][0]=i2; board[2][0]=i3; board[2][0]=i4;
  board[0][1]=i5; board[1][1]=i6; board[2][1]=i7; board[2][1]=i8;
  board[0][2]=i9; board[1][2]=i10; board[2][2]=i11; board[2][2]=i12;
  board[0][3]=i13; board[1][3]=i14; board[2][3]=i15; board[2][3]=i16;

  if (msg) printf("%s - ",msg); 
  else {
    printf("Board operation on {{%d,%d,%d,%d},...} yields {{%d,%d,%d,%d}...} - ",
	   i1,i2,i3,i4,o1,o2,o3,o4);
  }
  fflush(stdout);
  func(4,board);
  if (
      (board[0][0]!=o1)||(board[1][0]!=o2)||(board[2][0]!=o3)||(board[3][0]!=o4)||
      (board[0][1]!=o5)||(board[1][1]!=o6)||(board[2][1]!=o7)||(board[3][1]!=o8)||
      (board[0][2]!=o9)||(board[1][2]!=o10)||(board[2][2]!=o11)||(board[3][2]!=o12)||
      (board[0][3]!=o13)||(board[1][3]!=o14)||(board[2][3]!=o15)||(board[3][3]!=o16)
      )
    {
      printf("FAILED: {{%d,%d,%d,%d},{%d,%d,%d,%d},{%d,%d,%d,%d},{%d,%d,%d,%d}} became {{%d,%d,%d,%d},{%d,%d,%d,%d},{%d,%d,%d,%d},{%d,%d,%d,%d}} instead of"
	     " {{%d,%d,%d,%d},{%d,%d,%d,%d},{%d,%d,%d,%d},{%d,%d,%d,%d}}\n",
	     i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15,i16,
	     board[0][0],board[1][0],board[2][0],board[3][0],
	     board[0][1],board[1][1],board[2][1],board[3][1],
	     board[0][2],board[1][2],board[2][2],board[3][2],
	     board[0][3],board[1][3],board[2][3],board[3][3],
	     o1,o2,o3,o4,o5,o6,o7,o8,o9,o10,o11,o12,o13,o14,o15,o16);
      return -1;
    } 
  printf("PASSED.\n");
  return 0;
}

int ttl_vector(int i1,int i2,int i3,int i4,char *msg,
	       int o1,int o2,int o3,int o4)
{
  return line_vector_test(i1,i2,i3,i4,msg,o1,o2,o3,o4,tilt_line_left);
}

int test_tilt_left()
{
  int e=0;
  e|=ttl_vector(0,0,0,0,"Empty list is empty after shift",0,0,0,0);
  e|=ttl_vector(1,0,0,0,"Value on left stays on left after shift",1,0,0,0);
  e|=ttl_vector(0,0,0,1,"Value on right shifts to left edge after shift",1,0,0,0);
  e|=ttl_vector(0,0,1,0,"Value in middle shifts to left edge after shift",1,0,0,0);
  e|=ttl_vector(1,2,4,8,"Distinct values don't combine",1,2,4,8);
  e|=ttl_vector(1,1,1,1,"Combinations don't cascade",2,2,0,0);
  e|=ttl_vector(0,0,1,1,NULL,2,0,0,0);
  e|=ttl_vector(4,0,1,1,NULL,4,2,0,0);
  e|=ttl_vector(2,0,1,1,NULL,2,2,0,0);
  return e;
}

int test_rotate_board()
{
  board_vector_test(0,0,0,0,"Tilt 2x2 board left",0,0,0,0,tilt_board_left);
  board_vector_test(1,0,0,0,"Tilt 2x2 board left",1,0,0,0,tilt_board_left);
  board_vector_test(0,1,0,0,"Tilt 2x2 board left",1,0,0,0,tilt_board_left);
  board_vector_test(0,1,0,1,"Tilt 2x2 board left",1,0,1,0,tilt_board_left);
  board_vector_test(0,1,0,1,"Tilt 2x2 board up",0,2,0,0,tilt_board_up);
  board_vector_test(0,2,0,0,"Tilt 2x2 board up",0,2,0,0,tilt_board_up);

  board_vector_test(1,2,3,4,"Rotate 2x2 board right (+90)",3,1,4,2,board_rotate_90);
  board_vector_test(1,2,3,4,"Rotate 2x2 board 180",4,3,2,1,board_rotate_180);
  board_vector_test(1,2,3,4,"Rotate 2x2 board left (+270)",2,4,1,3,board_rotate_270);
  board3_vector_test(1,2,3,4,5,6,7,8,9,"Rotate 3x3 board right (+90)",
		     7,4,1,8,5,2,9,6,3,board_rotate_90);
  board3_vector_test(1,2,3,4,5,6,7,8,9,"Rotate 3x3 board 180",
		     9,8,7,6,5,4,3,2,1,board_rotate_180);
  board3_vector_test(1,2,3,4,5,6,7,8,9,"Rotate 3x3 board left (+270)",
		     3,6,9,2,5,8,1,4,7,board_rotate_270);

  board4_vector_test(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
		     "Rotate 4x4 board right (+90)",
		     13,9,5,1,14,10,6,2,15,11,7,3,16,12,8,4,
		     board_rotate_90);
  return 0;
}

int main(int argc,char **argv)
{
  int e=0;
  e|=test_tilt_left();
  e|=test_rotate_board();
  return e;
}
