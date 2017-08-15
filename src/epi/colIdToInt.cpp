#include <iostream>

int decodeColId(const std::string &col){
  int result = 0;
  for (char ch:col){
    //std::cout << ch << std::endl;
    ch = ch-'A'+1;
    result = 26*result+ ch;
    //std::cout << result << std::endl;
  }
  return result;
}

int main(){

  int val = decodeColId("ABC");
  std::cout << val << std::endl;

  val = decodeColId("ZZ");
  std::cout << val << std::endl;

  val = decodeColId("BA");
  std::cout << val << std::endl;

  val = decodeColId("AAA");
  std::cout << val << std::endl;

  val = decodeColId("AA");
  std::cout << val << std::endl;
}
