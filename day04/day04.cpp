#include <iostream>
#include <fstream>
#include <string>

void getNumbers(const std::string & s, int * array) {
  size_t pos = 0;
  size_t len = 0;
  size_t i = 0;

  while (pos <= s.length()) {
    array[i] = std::stoi(s.substr(pos), &len);
    pos += len + 1;
    i++;
  }
}

int main(int argc, char **argv) {
  if (argc != 2){
    std::cerr << "Incorrect number of arguments!" << std::endl;
    return 1;
  }
  std::ifstream input(argv[1]);

  if (!input.is_open()) {
    std::cerr << "Can't open file!" << std::endl; 
    return 1;
  }

  std::string line;
  int array[4];
  int sum = 0;

  while (std::getline(input, line))
  {
    getNumbers(line, array);
    //we need to find pairs which contain each other
    if (array[0] <= array[2] && array[1] >= array[3] ||
        array[2] <= array[0] && array[3] >= array[1])
      sum++;
  }
  
  std::cout << sum << std::endl;

  return 0;
}