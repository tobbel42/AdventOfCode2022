#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

#define ROW 2000000

#define MAX 4000000


inline int manhattan(int x1, int y1, int x2, int y2){
  return (abs(x1 - x2) + abs(y1 - y2));
}

struct Sensor{
  int x;
  int y;
  int manhattan;
};



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
  std::vector<Sensor> sensorList;

  while (std::getline(input, line)){
    
    x1 = std::stoi(line.substr(line.find("x=") + 2));
    x2 = std::stoi(line.substr(line.rfind("x=") + 2));
    y1 = std::stoi(line.substr(line.find("y=") + 2));
    y2 = std::stoi(line.substr(line.rfind("y=") + 2));
    
    Sensor tmp;
    tmp.x = x1;
    tmp.y = y1;
    tmp.manhattan = manhattan(x1, y1, x2, y2);

    sensorList.push_back(tmp);
  }

  //basiclly we check every tile if any sensor is in range
  //to speed up the proccess, we skip to the first tile out of range of the sensor in the given row; 

  for (int i = 0; i < MAX + 1; ++i){
    for (int j = 0; j < MAX + 1; ++j){
      
      bool flag = true;
      for (int k = 0; k < sensorList.size(); ++k){
        int diff = sensorList[k].manhattan - manhattan(i, j, sensorList[k].x, sensorList[k].y);
        if (diff < 0)
          continue;
        if (diff >= 0) {
          j = sensorList[k].manhattan - abs(i - sensorList[k].x) + sensorList[k].y;
          flag = false;
        }
      }
      if (flag){
        //casting to long cause big number 
        std::cout << "solution" << i << " " << j << " " << (long)i * (long)MAX + (long)j << std::endl;
        return 0;
      }
    }
  }
  return 0;
}