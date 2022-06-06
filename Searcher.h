//
// Created by GKurf on 2022/6/3.
//

#ifndef MYKWIC_SEARCHER_H
#define MYKWIC_SEARCHER_H

#include <iostream>
#include <algorithm>
#include "LineStorage.h"
using namespace std;
class SearchStrategy{
public:
    vector<string> makeSearch(LineStorage &LineStorage,vector<string> toSearch);
    virtual bool searchWord(string S,string P){};
};
class KMPSearch : public SearchStrategy{
public:
    vector<int> next{};
    void calcNext(string pattern);
    bool searchWord(string S,string P) override;
};
class ViolentSearch : public SearchStrategy{
public:
    bool searchWord(string S,string P) override;
};
class Searcher {
public:
    vector<string> toSearch{};
    void insertWords(vector<string> inputWords);
    SearchStrategy *strategy{};
    Searcher(int selectedStrategy);
    vector<string> doSearch(LineStorage &LineStorage);
};


#endif //MYKWIC_SEARCHER_H
