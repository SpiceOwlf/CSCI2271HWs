#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


LIST read_file();
int randomNumber(int upperBound);
node_t *search_next_color(node_t *square,char *color);
char *random_color_generate();
int *check_special(node_t *square);
