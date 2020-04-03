#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

void factorialgantitambah(){

}
int main(){
  key_t key = 1234;
  int shmid = shmget(key, sizeof(int)*i*j, IPC_CREAT | 0666);
  matriks = (int *)shmat(shmid, NULL, 0);


}
