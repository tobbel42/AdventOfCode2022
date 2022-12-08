#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool isVis(std::vector<std::vector<int>> map, int i, int j){
  for (int x = i - 1; x >= 0; --x){
    if(map[i][j] <= map[x][j])
      break;
    else if (x == 0){
      return true;
    }

  }
  for (int x = i + 1; x < map.size(); ++x){
    if(map[i][j] <= map[x][j])
      break;
      else if (x == map.size() - 1){
        return true;
    }
  }
  for (int y = j - 1; y >= 0; --y){
    if(map[i][j] <= map[i][y])
      break;
    else if (y == 0){
      return true;
    }
  }
  for (int y = j + 1; y < map.size(); ++y){
    if(map[i][j] <= map[i][y])
      break;
    else if (y == map.size() - 1){
      return true;
    }
  }
  return false;
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

  std::vector<std::vector<int>> map;
  std::string line;

  while (std::getline(input, line)){
    std::vector<int> tmp;
    for (int i = 0; i < line.size(); ++i){
      tmp.push_back(static_cast<int>(line[i]));
    }
    map.push_back(tmp);
  }
  
  int sum = 0;

  for (int i = 1; i < map.size() - 1; ++i){
    for (int j = 1; j < map[0].size() - 1; ++j){
      if (isVis(map, j, i)){
        ++sum;
      }
    }
  }

  sum += 4 * map.size() - 4;

  std::cout << sum << std::endl;

  return 0;
}