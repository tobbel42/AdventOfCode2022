#include <iostream>
#include <fstream>
#include <set>

#define ROW 2000000

#define ROW 10

inline int manhattan(int x1, int y1, int x2, int y2){
  return (abs(x1 - x2) + abs(y1 - y2));
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
  size_t pos;
  int x1, x2, y1, y2;
  std::set<int> target;

  while (std::getline(input, line)){
    
    x1 = std::stoi(line.substr(line.find("x=") + 2));
    x2 = std::stoi(line.substr(line.rfind("x=") + 2));
    y1 = std::stoi(line.substr(line.find("y=") + 2));
    y2 = std::stoi(line.substr(line.rfind("y=") + 2));
    
    std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;

    int diff = manhattan(x1, y1, x2, y2) - abs(y1 - ROW);
    std::cout << diff << std::endl;
    if (diff >= 0){
      for (int i = x1 - diff; i <= x1 + diff; ++i){
        target.insert(i);
      }
    }
  }

  std::cout << target.size() - 1 << std::endl;

  return 0;
}