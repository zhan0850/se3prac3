1. Introduction

This is the test plan for the game 2048 created using C. The program is developed 
in a test driven approach, so producing the tests is essential to the whole process.

The development is based on the skeleton code provided by Paul, including the 
following files:
	-2048.h
	-main.c
	-board.c
	-keyboard.c
	-tilt.c
	-Makefile


2. Test Methods

The main test method involved is unit testing. That is, individual functions will be 
tested separately to see if they can perform their expected tasks.

Integration testing technique is also applied to some magnitude to check if the 
separate modules can interact together to fulfill required functionalities.


3. Test Coverage

The file 2048.h lists all functions of this program. 

The following functions are implemented by the developer and are all involved in 
performing main functionalities of the program and thus are covered by unit testing:
	-void board_spawn_tile(int size,int **board);
	-int tile_counter(int adder);
	-int tilt_board_left(int size,int **board);
	-int tilt_board_right(int size,int **board);
	-int tilt_board_up(int size,int **board);
	-int tilt_board_down(int size,int **board);
	-int check_lose(int size, int **board);

The function play() is not tested. It is simply a loop in the main() function to 
execute all other functioning components. What's critical to this loop is the 
sequence of invocations to other functions in each iteration, but not its own 
output.

Since this program is developed by extending the skeleton code provided by Paul, the 
functions that are inherent in the skeleton code are not subjects of unit testing. 
These functions are:
	-int **board_create(int size);
	-int board_display(int size,int **board);
	-int parse_input(char *line);
	-int read_input();

However, board_create() and board_display() must be used in order to carry out the 
testing for all other components, so in a sense, they are subjects of the 
integration testing. 

Note that some functions in the skeleton code are not implemented and used at all 
(marked out in 2048.h). 


4. Test File

The file test.c is created to implement all tests. It includes unit tests for chosen 
components and integration tests, each of which contains adequate test cases.

4.1 test_tilts
The first 4 functions invoked in the main() function in test.c test the following 
functions in tilt.c:
	-int tilt_board_left(int size,int **board);
	-int tilt_board_right(int size,int **board);
	-int tilt_board_up(int size,int **board);
	-int tilt_board_down(int size,int **board);

After a user input is read and parsed, one of these functions are invoked to move 
all tiles on the board to one direction. In some cases, some pairs of the tiles with 
the same value are combined and the value is added together. In addition, a value 
is also returned to indicate the validity of the move.

The test cases include checking each tile's move direction and distance, as well as 
validity of each combining and values after each combining.


4.2 test_board_spawn_tile()

This function tests board_spawn_tile() in file board.c. The subject function is 
invoked after each valid move to spawn a tile at a random empty location with a 
value of 2 (80% chance) or 4 (20% chance).

The test checks whether or not a tile's value is changed from 0 to 2 or 4.


4.3 test_tile_counter()

This function tests tile_counter function in board.c. The tested function is invoked 
by board_spawn_tile() to increment number of tiles. It is also invoked when the 
game is reset to change number of tiles back to 0.

The test cases include checking the initial value returned by the function, and 
also values returned after increments and decrements.


4.4 test_check_lose()

This function tests check_lose() in board.c. The target function is invoked whenever 
the value returned by tile_counter() is equal to the square of board size to check 
if it is still possible for any further valid move. If so, user can continue the 
game; else, game is over. 

The test tests the value returned by the function in these cases:
	board is not full;
	board is full, but there exist some tiles can be combined;
	board is full, and no tiles can be combined.


4.5 test_check_win()

This function tests the functionality of winning the game. There is a test_win() 
function in board.c implemented in an earlier stage of development, but is not used 
anymore. The current winning functionality is implemented in play() in main.c. In
each iteration of the loop, a value returned by tilt functions is checked to see if 
the user has won the game. So this test is actually testing the returned values of 
the tilt functions.

The test cases cover the situations of not winning and not winning after tilting in 
each direction.


5. Results

All tests are passed.







