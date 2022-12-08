#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int getScore(std::vector<std::vector<int>> map, int i, int j){
  int sum[4] = {0, 0, 0, 0};
  for (int x = i - 1; x >= 0; --x){
    ++sum[0];
    if(map[i][j] <= map[x][j])
      break;
  }
  for (int x = i + 1; x < map.size(); ++x){
    ++sum[1];
    if(map[i][j] <= map[x][j])
      break;
  }
  for (int y = j - 1; y >= 0; --y){
    ++sum[2];
    if(map[i][j] <= map[i][y])
      break;
  }
  for (int y = j + 1; y < map.size(); ++y){
    ++sum[3];
    if(map[i][j] <= map[i][y])
      break;
  }
  return sum[0] * sum[1] * sum[2] * sum[3];
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
      tmp.push_back(line[i] - '0');
    }
    map.push_back(tmp);
  }


  
  int score = 0;
  int max_score = 0;

  for (int i = 1; i < map.size() - 1; ++i){
    for (int j = 1; j < map[0].size() - 1; ++j){
      score = getScore(map, i, j);
      if (score > max_score)
        max_score = score;
    }
  }

  std::cout << max_score << std::endl;

  return 0;
}