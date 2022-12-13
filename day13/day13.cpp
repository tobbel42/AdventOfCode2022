#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> splitPacket(const std::string & packet){
    std::vector<std::string> tmp;

    size_t start = 1;
    size_t end = start;

    std::string arg;

    while (start < packet.size())
    {
        //we have a number
        if (isdigit(packet[start])){
            while (isdigit(packet[end])){
                ++end;
            }
            arg = packet.substr(start, end - start);
            tmp.push_back(arg);
        }
        else if (packet[start] == '[') {
            int bracketCount = 1;
            ++end;
            while (bracketCount){
                if (packet[end] == '[')
                    ++bracketCount;
                else if (packet[end] == ']')
                    --bracketCount;
                ++end;
            }
            if (end > start + 1) {
                if (end == packet.size()) {
                    arg = packet.substr(start);
                }
                else {
                    arg = packet.substr(start, end - start);
                }
                tmp.push_back(arg);
            }
        }

        start = end + 1;
        end = start;
    }
    
    return tmp;
}

int cmpPacket(std::vector<std::string> leftArgs, std::vector<std::string> rightArgs) {

    int i = 0;
    int cmp = 0;

    while (i < leftArgs.size() && i < rightArgs.size()){
        //if both are digits
        if (isdigit(leftArgs[i][0]) && isdigit(rightArgs[i][0])) {
            int l = std::stoi(leftArgs[i]);
            int r = std::stoi(rightArgs[i]);

            if (l < r)
                return 1;
            else if (l > r)
                return -1;
        }
        //if both are Lists
        else if (leftArgs[i][0] == '[' && rightArgs[i][0] == '[') {
            cmp = cmpPacket(splitPacket(leftArgs[i]), splitPacket(rightArgs[i]));
        }
        else if (leftArgs[i][0] == '[') {
            std::vector<std::string> tmp;
            tmp.push_back(rightArgs[i]);
            cmp = cmpPacket(splitPacket(leftArgs[i]), tmp);
        }
        else if (rightArgs[i][0] == '[') {
            std::vector<std::string> tmp;
            tmp.push_back(leftArgs[i]);
            cmp = cmpPacket(tmp, splitPacket(rightArgs[i]));
        }
        if (cmp == 1)
            return 1;
        else if (cmp == -1)
            return -1;
        ++i;
    }
    if (leftArgs.size() < rightArgs.size())
        return 1;
    else if (rightArgs.size() < leftArgs.size())
        return -1;
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

    std::string leftPacket, rightPacket;
    int sum = 0;
    int index = 1;

    while(std::getline(input, leftPacket) && std::getline(input, rightPacket)){

        std::vector<std::string> leftArgs = splitPacket(leftPacket);
        std::vector<std::string> rightArgs = splitPacket(rightPacket);

        if (cmpPacket(leftArgs, rightArgs) == 1) {
            sum += index;
            std::cout << index << " true" << std::endl;
        }

        
        ++index;

        //consuming the empty line;
        std::getline(input, leftPacket);
    }

    std::cout << sum << std::endl;

  return 0;
}