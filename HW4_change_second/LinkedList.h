//linkedList.h for HW4

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  void * item;
  struct node * next;
  struct node * prev;
}node_t;

typedef struct doubleLinkedList{
	node_t *firstNode;
	node_t *lastNode;
}doubleLinkedList_t;

typedef doubleLinkedList_t * LIST;
// typedef node_t *LIST;//pointer to node_t

LIST create_new_list();
node_t *make_new_listnode(void * item);
void insert_end(LIST my_list,void *m);//insert the item in
void displayList_front_to_behind(LIST m, void (*print_data)(void * item));
void displayList_behind_to_front(LIST m, void (*print_data)(void * item));

void delete_it(LIST my_list, void *item_delete,int(*compare)(void *A,void*B));
void print_specific_item (LIST my_list, int index, void (*printFunction)(void *item));
//test funciton
void print_string(void *item);
