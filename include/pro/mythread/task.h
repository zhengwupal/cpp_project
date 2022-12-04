#ifndef INCLUDE_PRO_MYTHREAD_TASK_H_
#define INCLUDE_PRO_MYTHREAD_TASK_H_

#include <mutex>

#include "pro/mythread/common_data.h"

class Task {
 public:
  Task() { cd = new CommonData(1); };
  ~Task() { delete cd; };

  void Process1();
  void Process2();
  void ComputeTask(int a, int b);
  void SafeAddTask(int a, int b);
  void AtomicAddTask(int a);

 private:
  std::mutex mtx_;
  CommonData *cd;
};

#endif  // INCLUDE_PRO_MYTHREAD_TASK_H_