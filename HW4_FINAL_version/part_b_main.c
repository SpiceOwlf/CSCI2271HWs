#include "square.h"
// #include "LinkedList.h"
#include "part_b_main_support.h"


int main(int argc, char const *argv[]) {
  char * local_color;
  char *extra_color;
  int steps_to_move;
  int counter=0;

  LIST PLAYER_list = create_new_list();
  //here a new player list is built
  node_t *player =NULL;
  //create this player node
  LIST main_d_list = read_file();

  node_t *HEAD=main_d_list->firstNode;
  node_t *TAIL =main_d_list->lastNode;;


  displayList_front_to_behind(main_d_list,print_square );
  printf("waiting....\n" );
   srand((unsigned)time(NULL));

while (1) {

  counter++;
  char* random_color =random_color_generate();

  node_t *temp_record=player;
  player=move_once(player,random_color,HEAD,TAIL);

////////////////////////////////////////////////
//test for special
  if(player!=temp_record){
  PLAYER temp_player_record=create_new_player("PLAYER_ONE",player->item);
//HERE IS A POTENTIAL PROBLEM
  insert_end(PLAYER_list,temp_player_record);



  int special=*check_special(player);

  if(special==3){
    printf("you win\n" );
    break;
  }else if(special==1){
    //this is GOBACK
    int record_move= special_move(player->item);
    for(int i=0;i<record_move; i++){
      player=player->prev;
    }

  }else if(special ==2){
    //this is GOFORWARD
    int record_move= special_move(player->item);
    for (int i=0;i<record_move; i++){
      player=player->next;
    }
  }
  ////////////////////////////////////
  // printf("%s\n", random_color);
/////////////////////////////////////
  special=*check_special(player);
  if(special==3){
    printf("you win\n" );
    break;

  }

  // counter++;
}

 }
 displayList_front_to_behind(PLAYER_list,print_player);
  printf("it takes %d steps\n",counter);
 return 0;
}
