#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>


LIST read_file();
int randomNumber(int upperBound);
node_t *search_next_color(node_t *square,char *color);
//MAY HAVE PROBLEM
char *random_color_generate();
//this will give you a random color
int *check_special(node_t *square);
//this will check your special move


node_t *move_once(node_t *current_node, char *input, node_t *head, node_t *tail);
