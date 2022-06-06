//
// Created by GKurf on 2022/6/3.
//

#ifndef MYKWIC_OUTPUT_H
#define MYKWIC_OUTPUT_H

#include <iostream>
#include <algorithm>
#include "LineStorage.h"
class Output {
public:
    Output();
    void showUpperConnectedLines(LineStorage LineStorage);
    void showLines(vector<string> toShow);
};


#endif //MYKWIC_OUTPUT_H
