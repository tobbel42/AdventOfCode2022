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

struct packet {
    std::string line;

    //added custom cmp operator so we can use sort
    bool operator < (const packet & rhs) const {
        if (cmpPacket(splitPacket(line), splitPacket(rhs.line)) == 1)
            return true;
        return false;
    }
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
    std::vector<packet> list;

    while(std::getline(input, line)){

        if (line == "")
            continue;

        packet tmp;
        tmp.line = line;

        list.push_back(tmp);
    }

    packet t1, t2;
    t1.line = "[[2]]";
    t2.line = "[[6]]";

    list.push_back(t1);
    list.push_back(t2);

    std::sort(list.begin(), list.end());

    int i1, i2;
    int index = 1;

    for (auto val : list){
        if (val.line == "[[2]]")
            i1 = index;
        if (val.line == "[[6]]")
            i2 = index; 
        ++index;
    }

    std::cout << i1 * i2 << " " << i1 << " " << i2 << std::endl;

  return 0;
}