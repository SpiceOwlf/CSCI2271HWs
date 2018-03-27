#include "square.h"
SQUARE new_square(char *color, char *special_needs, int move){
  //receive needed info and return a SQUARE type
  SQUARE local_square;
  local_square=(SQUARE)malloc(sizeof(square_t));
  local_square->color=(char*)malloc(sizeof(char)*20);
  local_square->special=(char*)malloc(sizeof(char)*20);

  strcpy(local_square->color, color);
  strcpy(local_square->special, special_needs);
  local_square->x=move;

  return local_square;
}

SQUARE make_square_node(char buffer[]){
  //build a new square from strings with new_square()
  SQUARE S;
  char *color, *special, *special_move;
  int move_number;
  color=(char *)malloc(sizeof(char)*80);
  special=(char *)malloc(sizeof(char)*80);
  special_move=(char *)malloc(sizeof(char)*80);

  color=strtok(buffer, " ");
  special= strtok(NULL," ");
  special_move=strtok(NULL," ");

  move_number=atoi(special_move);
  S=new_square(color,special,move_number);//build a new square
  return S;
}

void print_square(void *item){
  SQUARE s;
  char *color,*special;
  int number;
  s=(SQUARE)item;
  color=s->color;
  special=s->special;
  number=s->x;
  printf("color:%s, special:%s, number:%d\n",color,special,number );
}
////////////////////////////////////////////////////////////
//new witten, not tested
char *get_color(void *item){
  SQUARE s;
  char *color;
  s= (SQUARE)item;
  color=s->color;
  return color;
}
char *get_special_action(void *item){
  SQUARE s;
  char *action;
  s= (SQUARE)item;
  action=s->special;
  return action;
}
int special_move(void *item){
  SQUARE s;
  s= (SQUARE)item;
  return s->x;
}
////////////////////////////////////////////////////////////
char *num_to_color(int rn){
  //may need change to capital
  int local=rn;
  char *result_color;
  result_color=(char*)malloc(sizeof(char)*20);
  if(local==1){
     result_color="RED";
  }else if(local==2){
     result_color="BLUE";
  }else if(local==3){
    result_color="ORANGE";
  }else if(local==4){
    result_color="GREEN";
  }else{
    result_color="WRONG";
  }
  return result_color;
}
