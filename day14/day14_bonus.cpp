#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::pair<int, int> > rockPath(const std::string & line){

  std::vector<std::pair<int, int> > tmp;

  size_t pos = 0;

  while (pos < line.size()){
    
    std::pair<int, int> t;
    t.first = std::stoi(line.substr(pos));
    pos = line.find(',', pos);
    ++pos;
    t.second = std::stoi(line.substr(pos));
    tmp.push_back(t);
    pos = line.find(">", pos);
    if (pos != std::string::npos) {
      pos += 2;
    }
  }
  return tmp;
}

int dropSand(char map[164][400]){
  int c = 0;
  int offset_x = 300;
  while(true){
    std::pair<int, int> sand;
    sand.first = 0;
    sand.second = 500;

    while (true)
    {
      if (map[sand.first + 1][sand.second - offset_x] == '.'){
        ++sand.first;
      }
      else if (map[sand.first + 1][sand.second - 1 - offset_x] == '.'){
        ++sand.first;
        --sand.second;
      }
      else if (map[sand.first +1][sand.second + 1 - offset_x] == '.'){
        ++sand.first;
        ++sand.second;
      }
      else{
        if (sand.first == 0 && sand.second == 500)
          return c + 1;
        map[sand.first][sand.second - offset_x] = 'o';
        break;
      }
    }  
    ++c; 
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

  int x,y;
  std::string line;


  char map[165][400];
  for (int i = 0; i < 164; ++i){
    for (int j = 0; j < 400; ++j) {
      map[i][j] = '.';
    }
  }
  for (int i = 0; i < 400; ++i) {
    map[164][i] = '#';
  }
  
  // for (int i = 0; i < 400; ++i) {
  //   map[11][i] = '#';
  // }

  int offset_x = 300;


  while(std::getline(input, line)){
    auto path = rockPath(line);

    for (int i = 1; i < path.size(); ++i) {

      if (path[i].first > path[i - 1].first){
        for (int j = path[i - 1].first - offset_x; j <= path[i].first - offset_x; ++j){
          map[path[i].second][j] = '#';
        }
      }
      else if (path[i].first < path[i - 1].first){
        for (int j = path[i].first - offset_x; j <= path[i - 1].first - offset_x; ++j){
          map[path[i].second][j] = '#';
        }
      }
      else if ( path[i].second > path[i - 1].second){
        for (int j = path[i - 1].second; j <= path[i].second; ++j){
          map[j][path[i].first - offset_x] = '#';
        }
      }
      else if ( path[i].second < path[i - 1].second){
        for (int j = path[i].second; j <= path[i - 1].second; ++j){
          map[j][path[i].first - offset_x] = '#';
        }
      }
    }
  }

  int max_x = 517;
  int min_x = 462;
  int max_y = 162;


  std::cout << dropSand(map) << std::endl;  


 for (int i = 0; i < 165; ++i){
    for (int j = 0; j < 400; ++j) {
      std::cout << map[i][j];
    }
    std::cout << std::endl;
  }

  return 0;
}