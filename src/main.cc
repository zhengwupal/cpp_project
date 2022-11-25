#include <iostream>

#include "cppproject_config.h"
#include "pro/module_a/abc.h"
#include "pro/module_b/def.h"

int main(int argc, char const *argv[]) {
  test1();
  test2();
  if (argc < 2) {
    // report version
    std::cout << argv[0] << " Version " << CppProject_VERSION_MAJOR << "."
              << CppProject_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  const double inputValue = std::stod(argv[1]);

  // TODO 12: Use mysqrt if USE_MYMATH is defined and sqrt otherwise

  // TODO 6: Replace sqrt with mysqrt

  // calculate square root
  const double outputValue = mysqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;

  return 0;
}
