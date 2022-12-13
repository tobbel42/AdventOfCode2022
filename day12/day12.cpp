#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <functional>
#include <set>


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

    std::vector<std::vector<char> > map;
    std::string line;

    //reading the map

    while (std::getline(input, line)){
        std::vector<char> tmp;
        for (int i = 0; i < line.size(); ++i){
            tmp.push_back(line[i]);
        }
        map.push_back(tmp);
    }

    std::set<std::pair<int, int> > current_tiles;
    std::set<std::pair<int, int> > tiles;
    char current_height = 'a';
    int steps = 0;

    for (size_t i = 0; i < map.size(); ++i){
        for (size_t j = 0; j < map.size(); ++j){
            if (map[i][j] == 'S') {
                std::pair<int, int> tmp(i, j);
                tiles.insert(tmp);
            }
        }
    }

    while (current_tiles != tiles)
    {
        current_tiles.swap(tiles);
        tiles.clear();

        for (auto iter = tiles.begin(); iter != tiles.end(); ++iter){
            //top
            if ((*iter).first > 0){
                if (map[(*iter).first - 1][(*iter).second] == current_height){
                    std::pair<int, int> tmp((*iter).first - 1, (*iter).second);
                    tiles.insert(tmp);
                }
                // if (map[(*iter).first - 1][(*iter).second] + 1 == current_height){
                //     current_height += 1;
                //     tiles.insert()
                // }
            }
            //bottom
            if ((*iter).first + 1 < map.size()){
                if (map[(*iter).first + 1][(*iter).second] == current_height){
                    std::pair<int, int> tmp((*iter).first + 1, (*iter).second);
                    tiles.insert(tmp);
                }
            }
            //left
            if ((*iter).second > 0){
                if (map[(*iter).first][(*iter).second - 1] == current_height){
                    std::pair<int, int> tmp((*iter).first, (*iter).second - 1);
                    tiles.insert(tmp);
                }
            }
            //right
            if ((*iter).second + 1 < map[0].size()){
                if (map[(*iter).first][(*iter).second + 1] == current_height){
                    std::pair<int, int> tmp((*iter).first, (*iter).second + 1);
                    tiles.insert(tmp);
                }
            }
        }
        ++steps;
    }

    std::cout << steps << std::endl;

    return 0;
}