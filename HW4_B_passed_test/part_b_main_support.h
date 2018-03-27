#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "LinkedList.h"
typedef struct player{
  char *name;
  SQUARE *ptr_to_node;
}player_t;

typedef player_t *PLAYER;

//not tested
PLAYER create_new_player(char* name,SQUARE *item);
//create newplaye with name and a node_t(void here)
void print_player(void *item);
//should save node, and print node,
//////////////////////////////////



LIST read_file();
int randomNumber(int upperBound);
node_t *search_next_color(node_t *square,char *color);
//MAY HAVE PROBLEM
char *random_color_generate();
//this will give you a random color
int *check_special(node_t *square);
//this will check your special move
node_t *move_once(node_t *current_node, char *input, node_t *head, node_t *tail);
