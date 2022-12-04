#ifndef INCLUDE_PRO_MYTHREAD_TASK_H_
#define INCLUDE_PRO_MYTHREAD_TASK_H_

#include <mutex>

class Task {
 public:
  Task(){};
  ~Task(){};

  void Process();
  void ComputeTask(int a, int b);
  void SafeAddTask(int a, int b);

 private:
  std::mutex mtx_;
};

#endif  // INCLUDE_PRO_MYTHREAD_TASK_H_