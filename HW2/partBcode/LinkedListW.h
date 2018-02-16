#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct word{
  char * content;
  int frequency;
  int * lineNum;
  //this is a dynamically allocated list of int representing the line numbers                            //in which the word appears         int numberOfLines;         //this is the number of lines in which the word appears (you need this to realloc space for lineNumers 
  struct word *next;//points to next word in the linked list )
}word_t;


//void MostFreq(*word_t);//use to print most frequent word
//typedef word_t *WordPtr;
//WordPtr MakeAWord();//use to make a wordlinkedlist


/////////////////implement these

/* prototypes */
//NodePtr addAtFront(NodePtr L, NodePtr node);
//NodePtr reverseList(NodePtr L);
//void printList(NodePtr L);
