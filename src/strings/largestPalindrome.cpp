#include <iostream>
#include <string>
int main(){
    std::string input;
    getline (std::cin, input);
    std::string palindrome;
    int N = input.length();
    for(int sz = 1; sz <= N; ++sz){
      for(int i=0; i < N; ++i){
        std::string subStr = input.substr(i, sz);
        if(subStr.length() < sz) break;
        //std::cout << "Substring is:" << subStr << " for size :" << sz << std::endl;
        std::string reverseStr(subStr);
        std::reverse(reverseStr.begin(), reverseStr.end());
        if(subStr == reverseStr){
          palindrome = reverseStr;
          std::cout << "Palindrome for size :" << sz << ":"<< subStr << std::endl;
          break;
        }
      }
    }
    std::cout << "The largest Palindrome: " << palindrome << std::endl;
    return 0;
}
