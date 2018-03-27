#include "player.h"
#include "square.h"
// #include "LinkedList.h"
#include "part_b_main_support.h"

PLAYER create_new_player(char* name,node_t *item){
  //JUST like SQUARE
  char *local_name=name;
  PLAYER new_player=(player_t*)malloc(sizeof(player_t));
  new_player->name=(char*)malloc(sizeof(char)*20);

  strcpy(new_player->name,name);
  new_player->ptr_to_node=item;
  return new_player;
}

int main(int argc, char const *argv[]) {
  LIST PLAYER_1=create_new_list();
  LIST PLAYER_2=create_new_list();

  char * local_color;
  char *extra_color;
  int steps_to_move;


  node_t *player1 =NULL;
  node_t *player2 =NULL;
  PLAYER player_num_1 = create_new_player("Player1",player1);
  PLAYER player_num_2 = create_new_player("Player2",player1);

  int counter_1=0;
  int counter_2=0;


  LIST main_d_list = read_file();
  node_t *HEAD=main_d_list->firstNode;
  node_t *TAIL =main_d_list->lastNode;

  printf("waiting....\n" );
  srand((unsigned)time(NULL));
  while (1) {

    char* random_color =random_color_generate();
    //change here to see if it worksss
    // char* random_color ="RED";


    node_t *temp_record=player1;
    player1=move_once(player1,random_color,HEAD,TAIL);
    counter_1++;


    if(player1!=temp_record){

  //should be ok now
    int special=*check_special(player1);

    if(special==3){
      printf("player1 win\n" );
      break;
    }else if(special==1){
      //this is GOBACK
      int record_move= special_move(player1->item);
      for(int i=0;i<record_move; i++){
        player1=player1->prev;
      }

    }else if(special ==2){
      //this is GOFORWARD
      int record_move= special_move(player1->item);
      for (int i=0;i<record_move; i++){
        player1=player1->next;
      }
    }
     printf("Player1:%s\n", random_color);

    special=*check_special(player1);
    if(special==3){
      printf("player1 win\n" );
      break;

    }
  }
  ///////////////////////////////////////////
  char* random_color_2 =random_color_generate();
  //change here to see if it worksss
  // char* random_color ="RED";


  node_t *temp_record_2=player2;
  player2=move_once(player2,random_color_2,HEAD,TAIL);
  counter_2++;


  if(player2!=temp_record_2){

//should be ok now
  int special_2=*check_special(player2);

  if(special_2==3){
    printf("player2 win\n" );
    break;
  }else if(special_2==1){
    //this is GOBACK
    int record_move_2= special_move(player2->item);
    for(int i=0;i<record_move_2; i++){
      player2=player2->prev;
    }

  }else if(special_2 ==2){
    //this is GOFORWARD
    int record_move_2= special_move(player2->item);
    for (int i=0;i<record_move_2; i++){
      player2=player2->next;
    }
  }
   printf("Player2: %s\n", random_color_2);

  special_2=*check_special(player2);
  if(special_2==3){
    printf("player2 win\n" );
    break;

  }
}



////////////////////////
   }



  return 0;
}
