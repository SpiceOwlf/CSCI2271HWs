
#include "square.h"
// #include "LinkedList.h"
#include "part_b_main_support.h"



int main(int argc, char const *argv[]) {
  LIST PLAYER_1_LIST=create_new_list();
  LIST PLAYER_2_LIST=create_new_list();

  char * local_color;
  char *extra_color;
  int steps_to_move;


  node_t *player1 =NULL;
  node_t *player2 =NULL;

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
      PLAYER temp_player1_record_=create_new_player("PLAYER_ONE",player1->item);
      insert_end(PLAYER_1_LIST,temp_player1_record_);

  //should be ok now
    int special=*check_special(player1);

    if(special==3){
      printf("player1 win, his Name is:\n" );

      char* player_1_name=temp_player1_record_->name;
      printf("%s\n",player_1_name );

      printf("\n" );

//print out your player list;
      displayList_front_to_behind(PLAYER_1_LIST,print_player);



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
     // printf("Player1:%s\n", random_color);

    special=*check_special(player1);
    if(special==3){
      printf("player1 win, his Name is:\n" );


      char* player_1_name=temp_player1_record_->name;
      printf("%s\n",player_1_name );
      printf("\n" );


      displayList_front_to_behind(PLAYER_1_LIST,print_player);

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
    PLAYER temp_player2_record_=create_new_player("PLAYER_TWO",player2->item);
    insert_end(PLAYER_2_LIST,temp_player2_record_);

//should be ok now
  int special_2=*check_special(player2);

  if(special_2==3){
    printf("player2 win, his Name is:\n" );


    char* player_2_name=temp_player2_record_->name;
    printf("%s\n",player_2_name );
    printf("\n" );

    displayList_front_to_behind(PLAYER_2_LIST,print_player);

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
   // printf("Player2: %s\n", random_color_2);

  special_2=*check_special(player2);
  if(special_2==3){
    printf("player2 win, his Name is:\n" );

    char* player_2_name=temp_player2_record_->name;
    printf("%s\n",player_2_name );
    printf("\n" );

    displayList_front_to_behind(PLAYER_2_LIST,print_player);

    break;

  }
}



////////////////////////
   }



  return 0;
}
