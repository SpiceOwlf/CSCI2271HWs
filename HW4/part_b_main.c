#include "square.h"
#include "LinkedList.h"
#include "part_b_main_support.h"


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
