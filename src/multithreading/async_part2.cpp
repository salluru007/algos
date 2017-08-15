#include "iostream"
#include "string"
#include "thread"
#include "future"
#include "chrono"
#include "vector"

int main(){
  std::cout << "Main Thread id:" << std::this_thread::get_id() << endl;
  std::vector<std::future<void>> futures;
  for(int i=0; i < 10; i++){
    auto fut = std::async([]
    {
      std:: this_thread::sleep_for(std::chrono::seconds(2));
      std::cout << std::this_thread::get_id() << " ";

    });
    futures.push_back(std::move(fut));
  }
  std::for_each(futures.begin(), futures.end(), [](std::future<void> &)){

  }
  std::cout << std::endl;
  std::this_thread::sleep_for(std::chrono:seconds(10));
}
