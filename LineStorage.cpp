//
// Created by GKurf on 2022/6/1.
//

#include "LineStorage.h"
void LineStorage::pushBackConnectedLines(string toPush){
    connectedLines.push_back(toPush);
    return;
}
void LineStorage::pushBackWordLines(vector<string> toPush){
    wordLines.push_back(toPush);
    return;
}
int LineStorage::getNumberOfLines(){
    return static_cast<int>(wordLines.size());
}
vector<string> LineStorage::getConnectedLines() {
    return connectedLines;
}
void LineStorage::setConnectedLines(vector<string> toSet) {
    connectedLines.clear();
    connectedLines.assign(toSet.begin(),toSet.end());
    return;
}
vector<vector<string>> LineStorage::getWordLines(){
    return wordLines;
};