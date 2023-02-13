#ifndef INCLUDE_PRO_MYTHREAD_COMMON_DATA_H_
#define INCLUDE_PRO_MYTHREAD_COMMON_DATA_H_

#include <atomic>

class CommonData {
public:
  CommonData(int num) : num_(num){};
  ~CommonData(){};

  inline std::atomic<int> &GetNum() { return num_; };
  // inline int &GetNum() { return num_; };

private:
  std::atomic<int> num_;
  // int num_;
};

#endif // INCLUDE_PRO_MYTHREAD_COMMON_DATA_H_