//HW2
//LinkedListW.h
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct word{
	char *w;
	int length;
	int frequency;
	int *lineNumbers;
	int numberOfLines;
	struct word *next;
}word_t;


char *getLine(int *size);
int Stop(char *line, int size);
word_t *createWord(char *word, int len);
int same(word_t *head, word_t *new);
word_t *update(word_t *head, word_t *new);
int get_most(word_t *head);
word_t **most_freq(word_t *head, int most, int *length);
void printWord(word_t *word);
void printList(word_t *head);
void freeAll(word_t *head);
