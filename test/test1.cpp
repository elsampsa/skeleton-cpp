#include "glowing_indexer.h"

void test_1() {
  
std::cout << "test_1" << std::endl;
DerivedClass test_instance = DerivedClass();

test_instance.useSql();

}


void test_2() {
  
  
}


int main(int argc, char** argcv) {
  if (argc<2) {
    std::cout << argcv[0] << " needs an integer argument." << std::endl;
  }
  else {
    switch (atoi(argcv[1])) { // choose test
      case(1):
        test_1();
        break;
      case(2):
        test_2();
        break;
      default:
        std::cout << "No such test "<<argcv[1]<<" for "<<argcv[0]<<std::endl;
        break;
    }
  }
} 
