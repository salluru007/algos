#include "iostream"
#include "fstream"
#include <chrono>
#include <random>
auto minValue = [](int val0, int val1)->int{
  if (val0 < val1) return val0;
  else return val1;
};

struct sort_clock{
  std::chrono::time_point<std::chrono::system_clock> _start, _end;
  std::chrono::duration<double> _elapsed_seconds;
  sort_clock() = default; //Think about this

};
template<typename T>
void swap(std::vector<T> &data, const  int &index,const int &minIndex){
  T temp = data[index];
  data[index] = data[minIndex];
  data[minIndex] = temp;
}

template<typename T>
bool less(const T &minValue, const T &value){
  return (value < minValue);
}
template<typename T>
void selection_sort(std::vector<T> &data, int N){
  sort_clock  trackTime;
  trackTime._start = std::chrono::system_clock::now();
  for(int i=0; i<N; i++){
    int min = i;
    for(int j=i+1; j < N; j++){
      if(less(data[min], data[j])) min=j;
    }
    swap(data, i, min);
  }
  trackTime._end = std::chrono::system_clock::now();
  trackTime._elapsed_seconds = trackTime._end-trackTime._start;
  std::cout << "Finished Selection Sort in:" << trackTime._elapsed_seconds.count() << std::endl;
}

template<typename T>
void insertion_sort(std::vector<T> &data, int N){
  sort_clock  trackTime;
  trackTime._start = std::chrono::system_clock::now();
  for(int i=1; i<N ; i++){
    for(int j=i; j > 0; j--){
      if(less(data[j], data[j-1])){
        swap(data, j, j-1);
        }
    }
  }
  trackTime._end = std::chrono::system_clock::now();
  trackTime._elapsed_seconds = trackTime._end-trackTime._start;
  std::cout << "Finished Insertion Sort in:" << trackTime._elapsed_seconds.count() << std::endl;
}
template<typename T>
void merge_data(std::vector<T> &data, int low, int mid, int high){
  std::vector<T> aux;
  aux = data;
  int j = low, k = mid+1;
  for(int i = low; i <= high ; i++){
    if(j > mid) data.at(i) = aux.at(k++);
    else if(k > high) data.at(i) = aux.at(j++);
    else if(aux.at(j) < aux.at(k)) data.at(i) = aux.at(j++);
	  else data.at(i) = aux.at(k++);
  }
}

template<typename T>
void topdown_merge_sort(std::vector<T> &data,  int low, int high){
  if(high <= low) return;
  int mid_ = low +(high-low)/2; //Why?
  topdown_merge_sort(data, low, mid_) ;
  topdown_merge_sort(data,  mid_+1 , high);
  merge_data(data, low, mid_, high);

}

template<typename T>
void bottomup_merge(std::vector<T> &data, int lo, int high){
  sort_clock  trackTime;
  trackTime._start = std::chrono::system_clock::now();
  int N = high;
  for (int sz = 1; sz < N; sz+=sz){
    for(int lo =0; lo < N-sz; lo+=sz+sz){
      merge_data(data, lo, lo+sz-1, minValue(lo+sz+sz-1, N-1));
    }
  }
    trackTime._end = std::chrono::system_clock::now();
    trackTime._elapsed_seconds = trackTime._end-trackTime._start;
    std::cout << "Finished Bottom Merge Sort in:" << trackTime._elapsed_seconds.count() << std:: endl;
}

template<typename T>
void quick_sort(std::vector<T>&data, int low, int high)
{
  if(low < high){
    int pivot = partition(data, low, high);
    quick_sort(data, low, pivot);
    quick_sort(data, pivot+1, high);
  }
}

template<typename T>
int partition(std::vector<T> &data, int low, int high){
  T pivot_elem = data.at(low);
  int i = low, j = high;
  do{
    i++;
  }while(data.at(i) < pivot_elem)
}
template<typename T>
void printData(std::vector<T> &data, const std::string &sortName){
  std::cout << "Printing data for:" << sortName << std::endl;
  typename std::vector<T>::iterator iter; //without typename, this throws an error
  for(iter=data.begin(); iter!=data.end(); ++iter){
    std::cout << *iter << std::endl;
  }
}
//The main function will read a text file, copy the data
//int an array and display the time taken to sort the data
int main(int argc, char *argv[]){
  std::random_device rd;
  std::mt19937 gen(rd());
  int N = 50;
  std::uniform_real_distribution<> dis(1, 2000);
  std::vector<double> numbers;
  std::vector<double> numbers_aux;
  for (int n=0; n<N; ++n){
    numbers.emplace_back(dis(gen));
  }
  numbers_aux = numbers;
  selection_sort(numbers, N);
  printData<double>(numbers, "Selection Sort");
  numbers = numbers_aux;
  insertion_sort(numbers, N);
  printData<double>(numbers, "Insertion Sort");
  sort_clock  trackTime;
  trackTime._start = std::chrono::system_clock::now();
  numbers = numbers_aux;
  topdown_merge_sort(numbers, 0, N-1);
  trackTime._end = std::chrono::system_clock::now();
  trackTime._elapsed_seconds = trackTime._end-trackTime._start;
  std::cout << "Finished Merge Top Sort in:" << trackTime._elapsed_seconds.count() << std::endl;
  printData<double>(numbers, "Merge Sort");
  numbers = numbers_aux;
  bottomup_merge(numbers, 0, N);
  printData<double>(numbers, "Merge Sort Bottom Up Sort");
}
