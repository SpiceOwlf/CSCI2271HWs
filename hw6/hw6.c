#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 256
//problem:some shitty guy will getoff the car mid-way

int n,C;//n=passages, C=capacity of car
int extra_n=0;

//------------------------------------------------
pthread_mutex_t mutex1;
pthread_cond_t cond1;//tell customers you can board
pthread_cond_t cond2;
pthread_cond_t cond3;
pthread_cond_t cond4;
pthread_t c_thread[MAX];
pthread_t car_thread;


// customer function
void *customer(void* arg){
  int num=(int)arg;
  pthread_mutex_lock(&mutex1);
  pthread_cond_wait(&cond1,&mutex1);
//wait to board
  printf("i am customer #%d, I am bording\n",num );
  extra_n++;
  //extra_n tracks how many people has gone
  printf("%d customers left\n",n-extra_n );


  pthread_cond_wait(&cond2,&mutex1);//wait to getoff
  printf("#%d is getting off\n",num );

  pthread_mutex_unlock(&mutex1);
  sleep(1);

}

void *car(void){
  int counter=0;
  int extra_C=C;

  printf("i am car \n" );
//  pthread_mutex_lock(&mutex1);
while(1){
  while(counter<C){
    pthread_cond_signal(&cond1);//let customer board
    counter++;

    // pthread_cond_wait(&cond3,NULL);
    // //see if it is the last customer

  }
  sleep(1);
  while(counter!=0){
    pthread_cond_signal(&cond2);//let them fk off
    counter--;
  }
  if(extra_n==n){
    break;
  }
}
//  pthread_mutex_unlock(&mutex1);

}
//-------------------------------------------------------
int main(int argc, char *argv[]) {
  if(argc != 3) {
  printf("ERROR!!!! Give me augs.\n");
  exit(0);
  }

  n=atoi(argv[1]);
  C=atoi(argv[2]);
  printf("You entered: %d passages\n", n);
  printf("You entered: %d capacity of car\n\n", C);
  ////////////////////////////////////////////////
  pthread_mutex_init(&mutex1,NULL);
  pthread_cond_init(&cond1,NULL);
  pthread_cond_init(&cond2,NULL);
  pthread_cond_init(&cond3,NULL);


  //starts customer threads
  for (int i=0;i<n;i++){
    pthread_create(&c_thread[i],NULL,(void *)customer,(void*)i);
  }
    pthread_create(&car_thread,NULL,(void *)car,NULL);


  for(int i=0;i<n;i++){
    pthread_join(c_thread[i],NULL);
  }
    pthread_join(car_thread,NULL);

//destroy mutexs and cond
    pthread_mutex_destroy(&mutex1);
    pthread_cond_destroy(&cond1);
    pthread_cond_destroy(&cond2);



////////////////////////////////////////////////
return 0;
}
