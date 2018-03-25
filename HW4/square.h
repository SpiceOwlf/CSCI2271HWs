#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct square{
  char * color;    // the color of the space. either red, blue, orange or green;
  char * special;  // the special space. There are four values for special spaces: GOBACK, GOFORWARD
                   // WIN and NONE (i.e. nothing special)
  int x;           // if you land on a special space, this is how many spaces to move.
                   //If you land on WIN, the game is over and you win.
  }square_t;
typedef square_t *SQUARE;


SQUARE new_square(char *color, char *special_needs, int move);
SQUARE make_square_node(char buffer[]);
void print_square(void *item);
// char *to_string(void *item);
char *num_to_color(int rn);

char *get_color(void *item);
//check for color
char *get_special_action(void *item);
//check for special_move
int special_move(void *item);
//check for special_move number(int)
