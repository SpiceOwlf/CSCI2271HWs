#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seperateLine.h"

word_t countFreqency(word_t *unCounted){
  word_t *countedResutlt;
  word_t *store;

  int frequency=0;
  int lineNum=0;
  char *current;
  while (unCounted!=null){

    store=createWord(unCounted->content, *frequency, *lineNum);
    countedResutlt=insertWord(*countedResutlt,*store);
    unCounted=unCounted->next;
  }
  return countedResutlt;

}

int countT(*char, word_t *target){

}
