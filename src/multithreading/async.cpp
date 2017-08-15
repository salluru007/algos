#include "iostream"
#include "thread"
#include "exception"
#include "future"

std::string fun()

  std::string str("Hello from future");
  throw(std::exception("Exception from task!"));
  return str;

}
//No need of thread join
//thread join and future get are where the execution is enforced
int main()
{
  //async is for tasks, return futures
  auto fr = std::async(&fun); //asynchrous passing data
  std::cout << "Hello from main\n";
  try{
    str = ftr.get(); //Passing a  data from one thread to another
    std::cout << str << endl;
  }
  catch(std::exception &e){
    std::cout << e.what() << std::endl;
  }
  std::cout << str << std::endl;
}
//RUN THE BELOW CODE TOO
//Alternatively
// std::string fun()
//
//   std::string str("Start of  from future");
//   //sleep
//   std::string end("End of string");
//
// }

// int main(){
//   auto fr = std::async(&fun); //asynchrous passing data
//   std::cout << "Hello from main\n";
// }
