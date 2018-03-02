#include "HW3.h"

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



/////////////////////////////////////////////////////////////////////////////////




word_t *insert_block(word_t *old_block, word_t *new_block){
  word_t *local_head;
  word_t *temp_block;
  if (old_block==NULL){
    return new_block;
  };
   if(new_block ==NULL){
    return old_block;
  };
  local_head=old_block;
  while(old_block->next!=NULL){
    old_block=old_block->next;
  }
  old_block->next=new_block;
  new_block->next=NULL;

  return local_head;
}

word_t *get_string(){
  char *local;
  char item;
  int localNum=0;
  word_t *NewBlock;
  word_t *ResultBlock;

  item=getchar();

  while(item!='\n'){
    local=(char*) malloc(sizeof(char)*(localNum+1));
  while (localNum<80&&item!='\n'){
    *(local+localNum)=item;
    localNum++;
    local=realloc(local,sizeof(char)*(localNum+1));//realloc bug complete
    item=getchar();
  }
  *(local+localNum)='\0';
  NewBlock=create_block(local);
  ResultBlock=insert_block(ResultBlock,NewBlock);
  localNum=0;
}

  return ResultBlock;
}
void print_all(word_t *target){
  while(target!=NULL){
    printf("Chunk:");
    print_single_block(target);
    target=target->next;
  }
}

void FreeTheWorld(word_t *head){
  word_t *temp;
    while(head!=NULL){
      // free(head->w);
      temp=head;
      head=head->next;
      free(temp);
    }
    free(head);
}

/////////////////////////////////////////////////////////////////////
int main(){
  char *Line;
  char *Line2;
  char temp_char;
  int j, i;
  word_t *MyBlock;
  word_t *NewBlock;
  printf("GIVE ME THE LINE: \n" );

   MyBlock=get_string();
   print_all(MyBlock);
   printf("DONE \n" );
   FreeTheWorld(MyBlock);






// printf("/////////////////////////////////////////////");
//printf("\n");

return 0;


}
