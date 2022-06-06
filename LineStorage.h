//
// Created by GKurf on 2022/6/1.
//

#ifndef MYKWIC_LINESTORAGE_H
#define MYKWIC_LINESTORAGE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class LineStorage {
public:
    vector<string> connectedLines {};
    vector<vector<string>> wordLines{};
    void pushBackConnectedLines(string toPush);
    void pushBackWordLines(vector<string> toPush);
    int getNumberOfLines();
    vector<vector<string>> getWordLines();
    vector<string> getConnectedLines();
    void setConnectedLines(vector<string> toSet);
};


#endif //MYKWIC_LINESTORAGE_H
