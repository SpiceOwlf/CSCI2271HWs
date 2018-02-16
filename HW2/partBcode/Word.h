#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListW.h"
//create+insert;

word_t *createWord(char *content, int *frequency, int *lineNum){
    word_t *s=(word_t *)malloc(sizeof(word_t));
    char *n;
    s->content=(char*) malloc(sizeof(strlen(content)+1));
    s->frequency=*frequency;

    strcpy(s->content,content);
    return s;
}

word_t *insertWord(word_t *s, word_t *newWord){
  if(s==NULL){
    return newWord;
  }
  newWord->next=s;
  s=newWord;
  return s;
}
