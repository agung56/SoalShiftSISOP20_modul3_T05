# SoalShiftSISOP20_modul3_T05
#### Anggota Kelompok:
1. I Gede Pradhana Indra Widnyana (05311840000031
2. Agung Mulyono (05311840000035)


### [ink Soal Shift](https://github.com/agung56/SoalShiftSISOP20_modul3_T05/blob/master/SoalShiftModul3.pdf)

## Soal 1
Kode Program: [soal1.c](https://github.com/agung56/SoalShiftSISOP20_modul3_T05/tree/master/soal1)

## Soal 2
Kode Program: [soal2.c](https://github.com/agung56/SoalShiftSISOP20_modul3_T05/tree/master/soal2)

## Soal 3
Kode Program: [soal3.c](https://github.com/agung56/SoalShiftSISOP20_modul3_T05/blob/master/soal3/soal3.c)

## Soal 4
Kode Program: [soal4a.c](https://github.com/agung56/SoalShiftSISOP20_modul3_T05/blob/master/soal4/soal4a.c)
              [soal4b.c](https://github.com/agung56/SoalShiftSISOP20_modul3_T05/blob/master/soal4/soal4b.c)
              [soal4c.c](https://github.com/agung56/SoalShiftSISOP20_modul3_T05/blob/master/soal4/soal4c.c)
#### Penjelasan Script 4 A

#### Penjelasan Script 4 B


#### Penjelasan Script 4 C
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

### Output
![thread](Screenshot/Screenshot4C.png)
