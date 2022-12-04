#ifndef INCLUDE_PRO_MYTHREAD_THREAD_BASE_H_
#define INCLUDE_PRO_MYTHREAD_THREAD_BASE_H_

class ThreadBase {
 public:
  ThreadBase(){};
  ~ThreadBase(){};
  void BaseTest();
  void MutexTest();
};

#endif  // INCLUDE_PRO_MYTHREAD_THREAD_BASE_H_