#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int getLine(char *line){
	char *a,b;
	int i,size=0;
	a = line;
	b = getchar();
	while( b != '\n' && size < 80)
    {
		*(a+size) = b;  //remember at this point size = 0
		//printf("a = %c\n",*(a+size));
		size++;
		b = getchar();
    }
	return size;
}

void reverseString(char *line, int size){
  char *a;
  int i;
  a = line;
  for (i=size-1;i>=0;i--)
    printf("%c",*(a+i));
  printf("\n");

}

int main(){
  char *a;
  char m[80];
  int i, size=0;
  printf("Input: \t" );
  size = getLine(m);
  printf("Output\t" );
  reverseString(m,size);

return 0;
}
