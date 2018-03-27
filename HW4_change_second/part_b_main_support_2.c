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

char *random_color_generate(){
  char *local_color;
  // srand((unsigned)time(NULL));


  local_color=num_to_color(randomNumber(4));
  return local_color;

}


node_t *search_next_color(node_t *square,char *color){
//find next node which contains color we need
node_t *result;

  node_t *local_node=square->next;
  if(local_node==NULL){
    result=square;
  }else{
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
  }
    return result;
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
    }else if(strcmp(special_action,"WIN")==0){
      *result =3;
    }
    return result;
  }

  node_t *move_once(node_t *current_node, char *input, node_t *head, node_t *tail){
//input current node, color, first and last node;
  node_t *local=(node_t*)malloc(sizeof(node_t));
  char *head_color=get_color(head->item);
  if(current_node==NULL&&strcmp(input,head_color )==0){

    local=head;
    //if current has nothing, then set it to board
    //head
  }else if(current_node==NULL&&strcmp(input,head_color )!=0){
    local=head;
    local= search_next_color(local,input);
  }else{
    //if it has sth, then search for next node;
      local= search_next_color(current_node,input);
    }
    return local;
  //////////////////////////////////////
  // if(current_node==NULL&&strcmp(input,head_color )==0){
  //
  //   local=head;
  //   //if current has nothing, then set it to board
  //   //head
  // }else if(current_node==NULL&&strcmp(input,head_color )!=0){
  //   return current_node;
  // }else{
  //   //if it has sth, then search for next node;
  //     local= search_next_color(current_node,input);
  //   }
  //   return local;
  }




///////////////////////////////////////////////
