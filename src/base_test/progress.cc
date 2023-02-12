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
  printf("Hello, World1! %d\n", getpid());
  pid_t pid = fork();
  if (pid != 0) {
    printf("11111111111 %d\n", getpid());  // 父进程
    waitpid(pid, NULL, 0);                 // 父进程等待子进程结束
  }
  sleep(10);
  printf("Hello, World2! %d\n", getpid());
}