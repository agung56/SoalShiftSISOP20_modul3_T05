# Pembahasan Nomor 4


> ## #Script untuk 4 C
>
```c

#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int fd[2];

  pid_t t;

  if (pipe(fd)==-1){
    fprintf(stderr, "Pipe failed");
    return 1;
  }

  t = fork();

  if (t<0){
    fprintf(stderr, "Fork failed");
    return 1;
  }

  if (t==0){
    dup2(fd[1],1);
    close(fd[0]);
    close(fd[1]);

    char *jalan[]={"ls", NULL};
    execv("/bin/ls", jalan);
  }
  else{
    dup2(fd[0],0);
    close(fd[0]);
    close(fd[1]);
    char *jalan[] = {"wc", "-l", NULL};
    execv("/usr/bin/wc", jalan);
  }

  return 0;
}
```


## Penjelasan Script

```c
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
```

Script diatas merupakan semua library standar dalam bahasa pemrograman C yang digunakan dalam proses ini.
```c
int main() {
  int fd[2];

  pid_t t;

  if (pipe(fd)==-1){
    fprintf(stderr, "Pipe failed");
    return 1;
  }

  t = fork();

  if (t<0){
    fprintf(stderr, "Fork failed");
    return 1;
  }
```

selanjutnya untuk script diatas merupakan script dasar untuk membuat IPC pipes yaitu dengan pipe dan fork (seperti yang ada di dalam modul 3) yaitu dengan membuat 2 array dengan istilah sebagai 2 lubang pada pipa. dimana selanjutnya akan ada 2 tipe command yaitu 0 untuk read dan 1 untuk write
```c
  if (t==0){
    dup2(fd[1],1);
    close(fd[0]);
    close(fd[1]);

    char *jalan[]={"ls", NULL};
    execv("/bin/ls", jalan);
  }
```

selanjutnya adalah menggunakan pipe dan fork sebelumnya dengan menjalankan perintah **if dan else** untuk if yang pertama yaitu menjalankan perintah pertama yaitu perintah **Listing** atau **ls**. untuk terlebih dahulu melist semua jenis folder maupun file yang ada di dalam direktori tersebut.
```c
else{
    dup2(fd[0],0);
    close(fd[0]);
    close(fd[1]);
    char *jalan[] = {"wc", "-l", NULL};
    execv("/usr/bin/wc", jalan);
  }

  return 0;
}
```

Langkah terakhir dalam proses ini adalah dengan mengghitung jumlah hasil listing tersebut dengan command **wc -l** command tersebut merupakan command untuk menghitung satu persatu file ataupun folder yang sudah ada di dalam suatu **line** hasil dari proses listing sebelumnya, sehingga akan didapat jumlah dari file ataupun folder yang ada dalam direktori tersebut.


> ## #Screenshot program 4c
![thread](Screenshot/Screenshot4C.png)
