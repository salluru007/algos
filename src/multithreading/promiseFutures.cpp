#include "iostream"
#include "thread"
#include "exception"
#include "future"

void thFunc(std::promise<std::string> &&prms){
// try{
//   std::string str("Hello from future");
//   prms.set_value(str);
//   std::string errorFlag("Exception from Future!");
//   throw errorFlag;
//
// }
// catch(...){
//   prms.set_exception(std::current_exception());
// }
  std::string str("Hello from future!");
  prms.set_value(str);

}
void th2Func(std::promise<std::string> &prms_ref){
  std::string str("Hello from future for thread 2!");
  prms_ref.set_value(str);
  std::cout << str << std::endl;
}

int main()
{
  std::promise<std::string> prms;

  std::future<std::string> ftr = prms.get_future();
  std::thread th(&thFunc, std::move(prms)); //Try pass by reference
  std::cout << "Hello from main!\n";
  // try{
  //   std::string str = ftr.get(); //Passing a  data from one thread to another
  //   std::cout << str << std::endl;
  // }
  // catch(std::exception &e){
  //   std::cout << e.what() << std::endl;
  // }
  std::string str = ftr.get();
  std::cout << str << std::endl;
  th.join();

  //PASS BY REFERENCE
  std::promise<std::string> prms_ref;
  //std::future<std::string> ftr_ref = prms.get_future(); Since the th finish executing
  //prms goes out of scope.
  //std::future<std::string> ftr_ref = prms_ref.get_future(); Code still works
  std::thread th2(&th2Func, std::ref(prms_ref));
  //std::thread th3(&th2Func, std::ref(prms_ref)); this throws an error
  std::cout << "Hello from main pass by ref\n";
  std::future<std::string> ftr_ref = prms_ref.get_future();
  //std::future<std::string> ftr_ref2 = prms_ref.get_future(); //throws an error
  str = ftr_ref.get();
  //std::string str2 = ftr_ref2.get();
  //std::cout << str << "  " << str2 << std::endl;
  std::cout << str << std::endl;
  th2.join();
  //th3.join();

}
