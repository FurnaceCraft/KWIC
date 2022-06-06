//
// Created by GKurf on 2022/6/2.
//

#ifndef MYKWIC_SORTER_H
#define MYKWIC_SORTER_H
#include <iostream>
#include <algorithm>
#include "LineStorage.h"
using namespace std;
class SortStrategy{
public:
    virtual void makeSort(LineStorage &LineStorage){};
};
class QuickSort : public SortStrategy{
public:
    virtual void makeSort(LineStorage &LineStorage);
};
class BubbleSort : public SortStrategy{
public:
    virtual void makeSort(LineStorage &LineStorage);
};
class InsertSort : public SortStrategy{
public:
    virtual void makeSort(LineStorage &LineStorage);
};
class Sorter{
public:
    SortStrategy *strategy{};
    Sorter(SortStrategy *strategyName);
    void doSort(LineStorage &LineStorage);
};
#endif //MYKWIC_SORTER_H
