#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
std::unordered_map<std::string, int> wordCount;

void process(std::stringstream &line){
  std::string word;
  //std::cout << line.str() << std::endl;
  while(line >> word){
    //std::cout << word << std::endl;
    wordCount[word]++; //very simple hash function, need to a problem with a hash function
  }
}

int main(int argc, char*argv[]){
  //Read the file passed at the input
  std::string file_name = argv[1];
  std::fstream file_handle(file_name,std::ios::in);
  if(!file_handle.is_open()){
    std::cout << "File is not opened\n";
  }
  else{
    std::cout << "File is opened \n";
    std::string input;

    while(getline(file_handle, input)){
      std::stringstream line;
      line << input;
      //std::cout << input << std::endl;
      process(line);
      //line.flush();
      //std::cout << line.str() << std::endl;
    }
    std::unordered_map<std::string, int>::iterator iter;
    std::string threshold = argv[2];
    int max_word_count = std::stoi(threshold); //give this input as a threshold value
    std::string key_value;
    for(iter = wordCount.begin(); iter != wordCount.end();++iter){
      if(iter->second > max_word_count){
	         key_value = iter->first;
           max_word_count = iter->second;
           break;
      }
    }
    std::cout << "The max word is:" << key_value << ":" << wordCount[key_value] << std::endl;
  }
  file_handle.close();
  return 0;
}
