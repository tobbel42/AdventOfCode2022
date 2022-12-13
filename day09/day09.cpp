#include <iostream>
#include <fstream>
#include <set>

void updateTail(std::pair<int, int> & head, std::pair<int, int> & tail, std::set<std::pair<int, int> > & squares){
    int diffx = abs(tail.first - head.first);
    int diffy = abs(tail.second - tail.second);

    if (diffx == 2 )
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

    std::set<std::pair<int, int> >squares;

    int n;
    char c;

    std::pair<int, int > head(0, 0);
    std::pair<int, int > tail(0, 0);

  while (input.good())
  {
    input >> c >> n;
    
    switch (c)
    {
    case 'L':
        for (int i = 0; i < n; i++){
            head.second - 1;
        }
        break;
    case 'R':
        head.second + n;
        break;
    case 'U':
        head.first - 1;
        break;
    case 'D':
        head.first + 1;
        break;
    }
  }

  
  return 0;
}