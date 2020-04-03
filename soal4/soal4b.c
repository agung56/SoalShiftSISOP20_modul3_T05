#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>


int row=0;
int K[4][5];
void* factorialgantitambah(void* arg){
  int i= *((int*)arg);
  free(arg);

  int total=0;
  for(int a=i; a>0; a--){
    total=total+j;
  }

  if(row > 4){
    printf("\n");
    row=0;
  }
  printf("%4d", total);
  row++;

}
int main(){
  key_t key = 1234;
  int shmid = shmget(key, sizeof(int)*i*j, IPC_CREAT | 0666);
  matriks = (int *)shmat(shmid, NULL, 0);

  printf("Hasil Perkalian Matrix: \n");
  for(int b=0; b<i; b++){
    for(int c=0; c<j ; c++){
      printf("%2d\t", K[b][c]);
    }
    printf("\n");
  }

  printf("hasil setelah ditambah: \n");
  pthread_t tid[20];



  sleep(10);

  shmdt(matriks);
  shmctl(shmid, IPC_RMID, NULL);

}
