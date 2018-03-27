//linkedList.c  -- A GENERIC LINKED LIST
//HW4
#include "LinkedList.h"
LIST create_new_list(){
  LIST local_list;
  local_list=(LIST)malloc(sizeof(doubleLinkedList_t));
  local_list->firstNode=NULL;
  local_list->lastNode=NULL;
  return local_list;
}

node_t *make_new_listnode(void *item){//
  node_t *new_listnode;
  new_listnode=(node_t*)malloc(sizeof(node_t));
  new_listnode->item=item;
  new_listnode->next=NULL;
  new_listnode->prev=NULL;
  return new_listnode;
}

void insert_end(LIST my_list,void *m){//
  node_t *new_listnode=make_new_listnode(m);
  if (my_list->firstNode==NULL) {
    my_list->firstNode=new_listnode;
    my_list->lastNode=new_listnode;
    return;
  }
  new_listnode->prev=my_list->lastNode;
  my_list->lastNode->next=new_listnode;
  my_list->lastNode=new_listnode;
}

void displayList_front_to_behind(LIST my_list, void (*printFunction)(void *item)){
  node_t *temp=my_list->firstNode;
  while (temp!=NULL) {
    printFunction(temp->item);
    temp=temp->next;
  }
  printf("\n");
}

void displayList_behind_to_front(LIST my_list, void (*printFunction)(void * item)){
  node_t *temp=my_list->lastNode;
  while (temp!=NULL) {
    printFunction(temp->item);
    temp=temp->prev;
  }
  printf("\n");
}

/////////////////////////////////



void delete_it(LIST my_list, void *item_delete, int(*compare)(void *A,void*B)){
  //here,I need a compare funciton in board to compare elements;
  node_t *temp=my_list->firstNode;
  node_t *a, *b;//malloc?
  if(temp==NULL){
    printf("NOTHING TO DELETE\n" );
    return ;
  }else{
    while(temp!=NULL){
      if(compare(temp->item,item_delete)==1){//is this right
        a=temp->prev;
        b=temp->next;
        if(a!=NULL&&b!=NULL){//middle one
          a->next=b;
          b->prev=a;
          return ;
        }else if(a!=NULL && b==NULL){//last one
          a->next=NULL;
          return ;
        }else if(a==NULL &&b!=NULL){//first one
          b->prev=NULL;
          return ;
        }
      }else if(temp->next==NULL){
        printf("the item is not in this list\n");
        return ;
      }else{
        temp=temp->next;
      }
    }
  }
}

void print_specific_item (LIST my_list, int index, void (*printFunction)(void *item)){//not check
  int count=0;
  node_t *temp=my_list->firstNode;
  while (count<index){
    temp=temp->next;
    count++;
  }
  printFunction(temp->item);
}

/////
//test function
void print_string(void *item){
  char *local;
  local=(char*)item;
  printf("%s\n",local );

}
