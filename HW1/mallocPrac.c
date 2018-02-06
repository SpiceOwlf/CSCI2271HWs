#include <stdio.h>
#include <stdlib.h>


int main(){

  int*p;
  int n;
  printf("how many integers do you need:\n" );
  scanf("%d",&n );


  p=(int *)malloc(n * sizeof(int));
  int i;
  for (i = 0; i < n; i++) {
      printf("next number:\n" );
      scanf("%d",p+i );
  }
  printf("content\n" );
  for(i=0;i<n;i++){
    printf("%d",*(p+i) );
  }
  return 0;
}
