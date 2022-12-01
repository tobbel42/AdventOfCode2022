#include <iostream>
#include <fstream>

int main (int argc, char** argv)
{
  std::ifstream input(argv[1]);
  std::string line;
  int max_sums[3] = {0, 0, 0};
  int current_sum = 0;

  while (std::getline(input, line))
  {
    if (line == ""){
      if (current_sum > max_sums[0]){
        max_sums[2] = max_sums[1];
        max_sums[1] = max_sums[0];
        max_sums[0] = current_sum;
      } else if (current_sum > max_sums[1]){
        max_sums[2] = max_sums[1];
        max_sums[1] = current_sum;
      } else if (current_sum > max_sums[2]){
        max_sums[2] = current_sum;
      }
      current_sum = 0;
    }
    else {
      current_sum += std::stoi(line);
    }
  } 
  std::cout 
    << max_sums[0] << " "
    << max_sums[1] << " "
    << max_sums[2] << " "
    << max_sums[0] + max_sums[1] + max_sums[2] << std::endl;
  return (0);
}