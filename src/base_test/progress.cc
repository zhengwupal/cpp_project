#include "pro/base_test/progress.h"

#include <sys/wait.h>
#include <unistd.h>

#include <iostream>

void multiprogress() {
  // std::cout << "multiprogress" << std::endl;
  // std::cout << "main progress pid: " << getpid() << std::endl;
  // auto pid = fork();
  // if (pid == 0) {
  //   std::cout << "child progress pid: " << getpid() << std::endl;
  // } else if (pid == -1) {
  //   std::cout << "create child progress fail!" << std::endl;
  // } else {
  //   std::cout << "child progress pid: " << pid << std::endl;
  // }

  /*
   成功调⽤ fork() 会创建⼀个新的进程，它⼏乎与调⽤
fork()的进程⼀模⼀样，这两个进程都会继续运⾏。在⼦进程中，成功的 fork( )
调⽤会返回0。在⽗进程中 fork() 返回⼦进程的 pid。*/
  printf("Hello, World1! %d\n", getpid());
  pid_t pid = fork();
  printf("===========222222222 %d\n", pid);
  if (pid != 0) {
    printf("===========! %d\n", pid);
    printf("11111111111 %d\n", getpid());  // 父进程
    printf("====================== %d\n", pid);
    waitpid(pid, NULL, 0);  // 父进程等待子进程结束
  }
  sleep(10);
  printf("Hello, World2! %d\n", getpid());
}