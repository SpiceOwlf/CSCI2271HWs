#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "LinkedList.h"

typedef struct player{
  char *name;
  node_t *ptr_to_node;
}player_t;

typedef player_t *PLAYER;


PLAYER create_new_player(char* name,node_t *item);
//create newplaye with name and a node_t(void here)
