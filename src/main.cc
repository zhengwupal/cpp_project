#include <iostream>
#include <boost/di.hpp>
#include "pro/base/static.h"

namespace di = boost::di;

class MyClass {
private:
    int param1;
    double param2;

public:
    MyClass(int p1, double p2) : param1(p1), param2(p2) {}

    void displayParams() {
        std::cout << "Param1: " << param1 << ", Param2: " << param2 << std::endl;
    }
};

// 定义依赖注入模块
class MyModule : public di::config {
public:
    auto operator()() const {
        return di::make_injector(
            // 绑定类对象到对应的参数
            di::bind<int>.to(10),
            di::bind<double>.to(3.14)
            // 添加其他参数的绑定...
        );
    }
};

int main() {
    // // 创建依赖注入器
    // auto injector = di::make_injector(MyModule{}());

    // // 使用依赖注入器获取类对象
    // auto obj = injector.create<std::shared_ptr<MyClass>>();

    // // 使用对象的方法
    // obj->displayParams();
    test();

    return 0;
}
