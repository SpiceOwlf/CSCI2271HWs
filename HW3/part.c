#include "HW3.h"

char *get_string(int *record_num){//get all the chars and record the line size
  char *local;
  char item;
  int localNum=0;
  local=(char*) malloc(sizeof(char)*(localNum+1));
  item=getchar();
  while (item!='\n'){
    *(local+localNum)=item;
    localNum++;
    item=getchar();
  }
  *record_num=localNum;
  *(local+localNum)='\0';
  return local;
}



word_t *create_block(char *target){
  word_t *local_block;
  local_block=malloc(sizeof(word_t));
  local_block->w=target;
  local_block->next=NULL;
  return local_block;
}
void print_single_block(word_t *target){//print 80 chars
  char *p;
  int i=0;
  p=target->w;
  while(*(p+i)!='\0'){
    printf("%c",*(p+i));
    i++;
  }
  printf("\n" );
}

word_t *insert_block(word_t *old_block, word_t *new_block){
  word_t *local_head;
  if (old_block==NULL){
    local_head=new_block;
    return local_head;
  }
  local_head=old_block;
  // while (local_head->next!=NULL) {
  //   local_head=local_head->next;
  // }
  old_block->next=new_block;
  new_block->next=NULL;
  local_head=old_block;
  return local_head;
}
// void FreeTheWorld(word_t *target){
//   word_t *p;
// 	while (p!=NULL){
// 		free(p->w);
// 		free(p);
// 		p=p->next;
// 	}
// }
/////////////////////////////////////////////////////////////////////////////////
word_t *divide_into_80(char *target,int *record_num){
  int i;
  int j=0;
  char *temp;
  int hi;
  word_t *next_node=NULL;
  word_t *temp_block;
  word_t *head=NULL;

    temp=malloc(sizeof(char)*81);
    for(i=0;i<80;i++){
      *(temp+i)=*(target+j);
      j++;
    }//j=80
    *(temp+80)='\0';

    temp_block= create_block(temp);
    head=insert_block(head,temp_block);
    next_node=head;

    ///
  // good above

  while(*record_num-j>=80){
    temp=malloc(sizeof(char)*81);
    for(i=0;i<80;i++){
      *(temp+i)=*(target+j);
      j++;
    }
    *(temp+80)='\0';
    temp_block= create_block(temp);
    next_node=insert_block(next_node,temp_block);
    next_node=next_node->next;

  }


    hi=*record_num-j;
    temp=malloc(sizeof(char)*hi);
    for(i=0;i<hi;i++){
      *(temp+i)=*(target+j);
      j++;
    }
    temp_block= create_block(temp);
    next_node=insert_block(next_node,temp_block);
    next_node=next_node->next;



    return head;
}

/////////////////////////////////////////////////////////////////////
int main(){
  char *entireLine;
  char *anotherOne;
  int recordLineSize;
  word_t MyBlock;
  word_t MyBlock2;
  word_t *final;//use pointer to get *next value
  printf("print your line: \n");
  entireLine=get_string(&recordLineSize);
  MyBlock=*divide_into_80(entireLine, &recordLineSize);
//  printf("HHHHHHHHIIIII" );

  print_single_block(&MyBlock);
  final=MyBlock.next;
  while(final!=NULL){
    print_single_block(final);
    final=final->next;
  //  printf("LOOK AT ME" );
  }
//FreeTheWorld(final);
//FreeTheWorld(&MyBlock);
return 0;


}
