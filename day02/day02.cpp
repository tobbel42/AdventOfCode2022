#include <iostream>
#include <fstream>

int main(int argc, char**argv){

  std::ifstream input(argv[1]);

  char opponentShape, myShape;
  int score = 0;

  input >> opponentShape >> myShape;
  while (input.good())
  {
    if ((opponentShape - 'A' + 1) % 3 == myShape - 'X')
      score += 6;
    else if (opponentShape - 'A' == myShape - 'X')
      score += 3;
    score += myShape - 'X' + 1;
    std::cout << opponentShape << ' ' << myShape << ' ' << score << std::endl;
    input >> opponentShape >> myShape;
  }
  std::cout << score << std::endl;
}