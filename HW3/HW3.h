#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word{
       char * w;
       struct word *next;
}word_t;

char *get_string(int *record_num);
word_t *create_block(char *target);
void print_single_block(word_t *target);
word_t *insert_block(word_t *old_block, word_t *new_block);
word_t *divide_into_80(char *target, int *record_num);
void FreeTheWorld(word_t *head);

// abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz
//  abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz
//  abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz
//  abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxy
// zabcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz
