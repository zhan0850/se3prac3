int read_input();

#define GO_LEFT 1
#define GO_RIGHT 2
#define GO_UP 4
#define GO_DOWN 8
#define GO_NOWHERE 0
#define INVALID_INPUT -1


int **board_create(int size);
int board_display(int size,int **board);
int parse_input(char *line);
int read_input();
void board_spawn_tile(int size,int **board);
int tile_counter(int adder);
int tilt_board_left(int size,int **board);
int tilt_board_right(int size,int **board);
int tilt_board_up(int size,int **board);
int tilt_board_down(int size,int **board);
void play();
int check_lose(int size, int **board);
int check_win(int size, int **board);


//functions in test file
void test_tilt_left();
void test_tilt_right();
void test_tilt_up();
void test_tilt_down();
void tilt_test(char *msg, int func(int, int**), int size, int **input, int **output);
void test_board_spawn_tile();
void test_tile_counter();
void test_check_lose();
void test_check_win();
void reset(int size, int **board);


//not used
int combine_tiles(int length,int *line,int offset);
int tilt_through_empty_space(int length, int *line);
int tilt_line_left(int length,int *line);
