#include "square.h"
#include "LinkedList.h"
#include "part_b_main.h"
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
int main(int argc, char const *argv[]) {
  char * local_color;
  int steps_to_move;
  int counter=0;


  LIST main_d_list = read_file();
  node_t *main_ptr=main_d_list->firstNode;
  node_t *secondary_ptr=main_ptr;

  displayList_front_to_behind(main_d_list,print_square );
  while(1){
    int record_special_move;
    local_color=random_color_generate();
    printf("%s\n", local_color);
    secondary_ptr=search_next_color(secondary_ptr,local_color);

    if(secondary_ptr!=main_ptr){
      main_ptr=secondary_ptr;
      counter++;
      if(*check_special(main_ptr)==1){
        record_special_move=special_move(main_ptr->item);
        for(int i=0;i<record_special_move;i++){
          main_ptr=main_ptr->prev;
        }
      }else if(*check_special(main_ptr)==2){
        record_special_move=special_move(main_ptr->item);
        for(int i=0;i<record_special_move;i++){
          main_ptr=main_ptr->next;
      }

    }else if(secondary_ptr==main_ptr){
      counter++;

    }

     if(strcmp(get_special_action(main_ptr->item),"WIN")==0){
        break;
    }
  }

}
   printf("you used %d steps\n",counter );
  // char* test_color=get_color(test_node->item);


//   if(strcmp(test_color,"BLURE")==0)
//   {printf("yes it is red\n" );
// }else{
//   printf("NO it is not red\n" );
// }

  printf("done\n" );

 return 0;

}
