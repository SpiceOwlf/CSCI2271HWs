#include "LinkedListW.h"
#include "getLine.h"
#include "Word.h"

int main(){
  int lineSize;
  char *localc;

  localc=getLine(&lineSize);
  printf("%d\n",lineSize );
  return 0;
}
