#ifndef INCLUDE_PRO_MYTHREAD_COMMON_DATA_H_
#define INCLUDE_PRO_MYTHREAD_COMMON_DATA_H_

class CommonData {
 public:
  CommonData(int num) : num_(num){};
  ~CommonData(){};

  inline int GetNum() { return num_; };
  inline void UpdateNum(int num) { num_ = num; };

 private:
  int num_;
};

#endif  // INCLUDE_PRO_MYTHREAD_COMMON_DATA_H_