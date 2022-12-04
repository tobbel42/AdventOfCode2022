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
    // we need find pairs which overlap
    //this only works because the pairs are well formated, meaning p1 < p2
    // we check if begining of list one is before the end list two
    // and if the end of list one is after the beginnig of list two
    if (array[0] <= array[3] && array[1] >= array[2])
      sum++;
  }
  
  std::cout << sum << std::endl;

  return 0;
}