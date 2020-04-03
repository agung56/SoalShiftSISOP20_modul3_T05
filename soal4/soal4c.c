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

    char *argv[]={"ls", NULL};
    execv("/bin/ls", argv);
  }
  else{
    dup2(fd[0],0);
    close(fd[0]);
    close(fd[1]);
    char *argv[] = {"wc", "-l", NULL};
    execv("/usr/bin/wc", argv);
  }

  return 0;
}
