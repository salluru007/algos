#include "iostream"
#include "sstream"
using namespace std;

int popcount_4(uint64_t x) {
    int count;
    for (count=0; x; count++){
      x &= x-1;
      cout << "x:" << x << " count:" << count << "\n";
    }

    return count;
}

int main(){

  string inputData;
  stringstream input;
  int number;
  while(getline(cin, inputData)){
    input << inputData;
    if(input.str() != "")
      break;
  }
  input >> number;
  int countValue = popcount_4(number);
  cout << "The number of bits:" << countValue << "\n";
}
