#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int num;
  int count;

  if(argc != 2){
    fprintf(2, "usage: getcnt syscall-number\n");
    exit(1);
  }

  num = atoi(argv[1]);
  count = getcnt(num);
  if(count < 0){
    fprintf(2, "getcnt: invalid syscall number %d\n", num);
    exit(1);
  }

  printf("syscall %d has been called %d times\n", num, count);
  exit(0);
}
