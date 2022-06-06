//
// Created by GKurf on 2022/6/1.
//

#ifndef MYKWIC_INPUT_H
#define MYKWIC_INPUT_H


#include <iostream>
#include "LineStorage.h"
#include "Searcher.h"
using namespace std;
class Input {
public:
    void readFile(LineStorage &data);
    void readPattern(Searcher &Searcher);
    int readSearchStrategy();
    Input();

};

#endif //MYKWIC_INPUT_H
