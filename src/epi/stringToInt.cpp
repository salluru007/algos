#include<string>
#include<iostream>
#include<cmath>

int stringToInt(const std::string str){
  //int sign = str.compare(0, 1, "-") == 0 ? -1 :1;
  bool sign = str[0] == '-' ? true : false;
  int val = 0;
  //std::cout << str << " "<< startIndex << " " << sign << std::endl;
  for(int iter = sign ? 1 : 0; iter < str.length(); iter++ )
  {
      int digit = str[iter]-'0';
      val = val*10 + digit;
  }
  return (sign ? -val : val);

}

std::string intToString(int val){
  std::string strNum; bool isNegative;
  if(val < 0){
    val = -val, isNegative = true;
  }
  while(val != 0){
    strNum += '0' + val % 10;
    val = val /10;
    //strNum.push_back(ch);
  }
  if(isNegative){
    strNum +='-';
  }
  std::reverse(strNum.begin(), strNum.end());
  return strNum;
}

int main(){

  int number = stringToInt("123");
  std::cout << "Number:" << number << std::endl;
  int negNum = stringToInt("-123");
  std::cout << "Number:" << negNum << std::endl;
  std::string strNum = intToString(123);
  std::cout << "String:" << strNum << std::endl;
  std::string strNumNeg = intToString(-123);
  std::cout << "String:" << strNumNeg << std::endl;

}
