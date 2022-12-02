#include <iostream>
#include <fstream>

int calcScore(char opponentShape, char myShape){
  int score = 0;
  if ((opponentShape - 'A' + 1) % 3 == myShape - 'X')
    score += 6;
  else if (opponentShape - 'A' == myShape - 'X')
    score += 3;
  score += myShape - 'X' + 1;
  return score;
}

int main(int argc, char**argv){

  std::ifstream input(argv[1]);

  char opponentShape, myShape;
  int score = 0;
  input >> opponentShape >> myShape;
  while (input.good())
  {
    if (myShape == 'Y')
      myShape = opponentShape - 'A' + 'X';
    else if (myShape == 'Z')
      myShape = (opponentShape - 'A' + 1) % 3 + 'X';
    else {
      myShape = (opponentShape - 'A' + 3 - 1) % 3 + 'X';
    }

    score += calcScore(opponentShape, myShape);
    input >> opponentShape >> myShape;
  }
  std::cout << score << std::endl;
}