#include <iostream>
#include <fstream>
#include <vector>

struct Node {
  std::string name;
  size_t size;
  bool isDir;
  Node * parent;
  std::vector<Node *> children;
};

Node *newNode(std::string name, size_t size, bool isDir, Node * parent){
  Node * tmp = new Node;
  tmp->name = name;
  tmp->size = size;
  tmp->isDir = isDir;
  tmp->parent = parent;
  return tmp;
}

std::vector<std::string> splitLine(const std::string & line){
  std::vector<std::string> tmp;
  size_t start = 0;
  size_t end = line.find(' ', 0);
  while (true) {
    tmp.push_back(line.substr(start, end - start));
    if (end == std::string::npos)
      break;
    start = end + 1;
    end = line.find(' ', start);
  }
  return tmp;
}

void printTree(Node * node, int depth){
  for (int i = 0; i <  node->children.size(); ++i){
    for (int j = 0; j < depth; ++j)
      std::cout << " ";
    std::cout << "- " << node->children[i]->name 
      << " (" << (node->children[i]->isDir?"dir ":"file ")
      <<  "size=" << node->children[i]->size << ")" << std::endl;
    if (node->children[i]->isDir)
      printTree(node->children[i], depth + 1);
  }
}
size_t getSize(Node * node){
  size_t tmp = 0;
  for (int i = 0; i <  node->children.size(); ++i){
    if (node->children[i]->isDir)
      node->children[i]->size = getSize(node->children[i]);
    tmp += node->children[i]->size;
  }
  return tmp;
}

void findSmallest(Node *node, const size_t & totalSize, size_t & smallestSize){
  for (int i = 0; i <  node->children.size(); ++i){
    if (node->children[i]->isDir){
      findSmallest(node->children[i], totalSize, smallestSize);
      if (totalSize - node->children[i]->size <= 40000000) {
        if (smallestSize == 0 || node->children[i]->size < smallestSize)
          smallestSize = node->children[i]->size;
      }
    }
  }
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

  std::string line;
  std::vector<std::string> args;

  std::getline(input, line);
  Node * head = newNode("/", 0, true, NULL);
  Node * node = head;

  while (std::getline(input, line))
  {
    args = splitLine(line);
    if (args[0] == "$"){
      if (args[1] == "js")
        continue;
      else if (args[1] == "cd") {
        if (args[2] == "..")
          node = node->parent;
        else
        {
          for (size_t i = 0;  i < node->children.size(); ++i) {
            if (node->children[i]->name == args[2])
              node = node->children[i];
          }
        }
      }
    }
    else{
      if (args[0] == "dir")
        node->children.push_back(newNode(args[1], 0, true, node));
      else 
        node->children.push_back(newNode(args[1], std::stoi(args[0]), false, node));
    }
  }



  size_t totalSize = getSize(head);
  
  std::cout << totalSize << std::endl;

  size_t smallestDir = 0;

  findSmallest(head, totalSize, smallestDir);


  std::cout << smallestDir << std::endl;
  
  return 0;
}