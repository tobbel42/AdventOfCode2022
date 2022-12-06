#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <sstream>

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

  //we use the first line to determine the number of stacks

  std::getline(input, line);

  size_t n_of_stacks = (line.size() + 1) / 4;

  std::vector<std::stack<char>>stacks(n_of_stacks);

  for (size_t i = 1, n = 0; n < n_of_stacks; i += 4, ++n) {
    if (line[i] < 'A' || line [i] > 'Z')
      continue;
    stacks[n].push(line[i]);
  }

  // read the input
  while (std::getline(input,line))
  {
    if (line.size() == 0)
      break;
    for (size_t i = 1, n = 0; n < n_of_stacks; i += 4, ++n) {
      if (line[i] < 'A' || line [i] > 'Z')
        continue;
      stacks[n].push(line[i]);
    }
  }

  //because we read from the top we need to
  //swap the order of each of the stacks

  for (size_t i = 0; i < n_of_stacks; ++i) {
    std::stack<char> temp_stack;
    while(stacks[i].size()){
      temp_stack.push(stacks[i].top());
      stacks[i].pop();
    }
    std::swap(temp_stack, stacks[i]);
  }
  
  int n, from, to;


  while(std::getline(input, line)) {

    size_t bytes_read = 0;
    size_t temp;

    n = std::stoi(line.substr(5), &bytes_read);
    temp = bytes_read;
    from = std::stoi(line.substr(bytes_read + 5 + 6), &bytes_read);
    to = std::stoi(line.substr(5 + 6 +  4 + temp + bytes_read));

    for (int i = 0; i < n; ++i) {
      stacks[to - 1].push(stacks[from - 1].top());
      stacks[from - 1].pop();
    } 
  }

  

  for (size_t i = 0; i < n_of_stacks; ++i) {
    std::cout << stacks[i].top();
  }
  std::cout << std::endl;
  return 0;
}