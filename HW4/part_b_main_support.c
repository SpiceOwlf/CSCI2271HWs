#include "square.h"
#include "LinkedList.h"
#include "part_b_main_support.h"
/////////////////////////////////////

LIST read_file(){
  //read_file() should be in part_B_main.c
  LIST board = create_new_list();//create a doubleLinkedList
  char buffer[80];
  SQUARE S;//SQUARE NODE
  node_t *local_node;

 FILE *inf = fopen("board.txt","r");

 if(inf==NULL){
   printf("!!EMPTY FILE!!\n" );
   exit(1);
 }
 while (1) {
   fgets(buffer,80,inf);
   if(feof(inf))
   break;

   S=make_square_node(buffer);//not define
   insert_end(board,S);

 }
 fclose(inf);
 printf("Read in finished\n" );
 return board;
}

int randomNumber(int upperBound){
//this is the simple rn generator that generates a
//random number between 1 and upperBound
    int j;
    j=1+(rand() % upperBound);
    return j;
}

node_t *search_next_color(node_t *square,char *color){
//find next node which contains color we need

  node_t *local_node=square->next;
  node_t *result;
  //   if(strcmp(test_color,"BLURE")==0)
  //   {printf("yes it is red\n" );
  // }else{
  //   printf("NO it is not red\n" );
  // }
    while(1){
      if(strcmp(get_color(local_node->item),color)==0){
        result= local_node;
        break;
      }else if(local_node->next==NULL){
        result= square;
        break;
      }else{
        local_node=local_node->next;
      }
    }
    return result;
  }

  char *random_color_generate(){
    char *local_color;
    local_color=num_to_color(randomNumber(4));
    return local_color;

  }

  int *check_special(node_t *square){
    //0 nothing
    //1 GOBACK
    //2 GOFORWARD
    int *result;
    result =(int*) malloc(sizeof(int));
    char *special_action;
    special_action=get_special_action(square->item);
    if(strcmp(special_action,"NONE")==0){
      *result=0;
    }else if(strcmp(special_action,"GOBACK")==0){
      *result =1;
    }else if(strcmp(special_action,"GOFORWARD")==0){
      *result =2;
    }
    return result;
  }


///////////////////////////////////////////////
