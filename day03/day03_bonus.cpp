#include <iostream>
#include <fstream>

char multiStringUnion(
  const std::string & s1,
  const std::string & s2,
  const std::string & s3){
  for (auto iter = s1.begin(); iter != s1.end(); ++iter){
    if (s2.find(*iter) != std::string::npos && s3.find(*iter) != std::string::npos)
      return *iter;
  }
  return 0;
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

  std::string line1, line2, line3; 
  int sum = 0;
  char item;

  while(
    std::getline(input, line1) &&
    std::getline(input, line2) &&
    std::getline(input, line3)
    )
  {
    item = multiStringUnion(line1,line2,line3);

    if (item == 0)
      continue;
    
    sum += ((item < 'a')?(item - 'A' + 27):(item - 'a' + 1));
    // std::cout << item << " " << ((item < 'a')?(item - 'A' + 27):(item - 'a' + 1)) << " " <<  sum << std::endl;
  }
  
  std::cout << sum << std::endl;

  return 0;
}
