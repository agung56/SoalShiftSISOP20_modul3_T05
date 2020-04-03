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
int I[4][2] = {{2, 5},
               {3, 1},
               {4, 5},
               {2, 1},};
int J[2][5] = {{2, 3, 4, 5, 1},
               {4, 5, 1, 2, 3}};
int K[4][5];

void* perkalianmatrix(void* arg){
  int x=row++;

  for(int y=0; y<5; y++){
    for(int z=0; z<2; z++){
      K[x][y] = K[x][y] + I[x][z] * J[z][y];
    }
  }


}

int main(){
  int *matriks;
  int i=4,j=5;

  pthread_t tid[4];
  for(int a=0; a<4; a++){
    pthread_create(&tid[a], NULL, &perkalianmatrix, NULL);
  }
  for (int a=0; a<4; a++){
    pthread_join(tid[a], NULL);
  }

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
sleep(10);

shmdt(matriks);
shmctl(shmid, IPC_RMID, NULL);
}
