#include <iostream>
#include <fstream>
#define BYTECOUNT 14

int checkUnique(char *bytes) {
  for(int i = 0; i < BYTECOUNT; ++i){
    for (int j = i + 1; j < BYTECOUNT; ++j) {
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


  char bytes[BYTECOUNT] = {0};
  int index = BYTECOUNT - 1;
  int sum = BYTECOUNT - 1;
  char buffer;

  for (int i = 0; i < BYTECOUNT - 1; ++i) {
    input.get(bytes[i]);
  }

  while(input.get(buffer)) {
    ++sum;
    bytes[index] = buffer;
    if (checkUnique(bytes))
      break;
    ++index;
    if (index > BYTECOUNT - 1)
      index = 0;
  }

  std::cout << sum << std::endl;

  return 0;
}