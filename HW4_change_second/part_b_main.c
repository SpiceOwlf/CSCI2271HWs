#include "square.h"
#include "LinkedList.h"
#include "part_b_main_support.h"


int main(int argc, char const *argv[]) {
  char * local_color;
  char *extra_color;
  int steps_to_move;
  int counter=0;

  node_t *player =NULL;
  //create this player node
  LIST main_d_list = read_file();

  node_t *HEAD=main_d_list->firstNode;
  node_t *TAIL =main_d_list->lastNode;


  // node_t *test=move_once(HEAD,"RED",HEAD,TAIL);
  // test=move_once(test,"RED",HEAD,TAIL);
  // test=move_once(test,"RED",HEAD,TAIL);
  // test=move_once(test,"RED",HEAD,TAIL);
  // test=move_once(test,"RED",HEAD,TAIL);
  // test=move_once(test,"GREEN",HEAD,TAIL);
  //
  // int itest=*check_special(test);
  // printf("%d\n",itest );



  displayList_front_to_behind(main_d_list,print_square );
  printf("waiting....\n" );
   srand((unsigned)time(NULL));

while (1) {
// for(int j=0;j<20;j++){
  counter++;
  char* random_color =random_color_generate();
  //change here to see if it worksss
  // char* random_color ="RED";


  node_t *temp_record=player;
  player=move_once(player,random_color,HEAD,TAIL);



  if(player!=temp_record){

//should be ok now
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
  printf("%s\n", random_color);

  special=*check_special(player);
  if(special==3){
    printf("you win\n" );
    break;

  }

  // counter++;


}

 }
  printf("it takes %d steps\n",counter);
 return 0;
}
