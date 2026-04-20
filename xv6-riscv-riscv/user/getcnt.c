#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int syscall_num;
  int count;

  if(argc < 2){
    fprintf(2, "Usage: getcnt <syscall_number>\n");
    exit(1);
  }

  syscall_num = atoi(argv[1]);
  count = getcnt(syscall_num);

  if(count < 0){
    fprintf(2, "Error: invalid syscall number %d\n", syscall_num);
    exit(1);
  }

  printf("syscall %d has been called %d times\n", syscall_num, count);
  exit(0);
}
