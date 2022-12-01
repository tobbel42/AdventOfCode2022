#include <iostream>
#include <fstream>

int main (int argc, char** argv)
{
  std::ifstream input(argv[1]);
  std::string line;
  int max_sum = 0;
  int current_sum = 0;

  while (std::getline(input, line))
  {
    if (line == ""){
      if (current_sum > max_sum)
        max_sum = current_sum;
      current_sum = 0;
    }
    else {
      current_sum += std::stoi(line);
    }
  } 
  std::cout << max_sum << std::endl;
  return (0);
}