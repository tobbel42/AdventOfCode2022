#include <iostream>
#include <fstream>

int checkUnique(char *bytes) {
  for(int i = 0; i < 4; ++i){
    for (int j = i + 1; j < 4; ++j) {
      if (bytes[i] == bytes[j])
        return false;
    }
  }
  return true;
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


  char bytes[4] = {0, 0, 0, 0};
  int index = 3;
  int sum = 3;
  char buffer;

  input.get(bytes[0]);
  input.get(bytes[1]);
  input.get(bytes[2]);


  while(input.get(buffer)) {
    ++sum;
    bytes[index] = buffer;
    if (checkUnique(bytes))
      break;
    ++index;
    if (index > 3)
      index = 0;
  }

  std::cout << sum << std::endl;

  return 0;
}