//
// Created by GKurf on 2022/6/2.
//

#include "Sorter.h"
bool cmp(string a, string b){
    string str=" aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
    for(int i=0;i<min(a.size(),b.size());i++){
        if (str.find(a[i])>str.find(b[i]))
            return false;
        else if (str.find(a[i])<str.find(b[i]))
            return true;
        else
            continue;
    }
    if (a.size()<=b.size())
        return true;
    else
        return false;
}
Sorter::Sorter(SortStrategy *strategyName)
:strategy(strategyName)
{
    //cout<<"Sorter Created Successfully!"<<endl;
}
void Sorter::doSort(LineStorage &LineStorage) {
    strategy->makeSort(LineStorage);
    return;
}
void QuickSort::makeSort(LineStorage &LineStorage) {
    vector<string> tmp(LineStorage.getConnectedLines());
    //tmp.assign(LineStorage.getConnectedLines().begin(),LineStorage.getConnectedLines().end());
    sort(tmp.begin(),tmp.end(), cmp);
    LineStorage.setConnectedLines(tmp);
    return;
}
void BubbleSort::makeSort(LineStorage &LineStorage) {//unfinished
    return;
}
void InsertSort::makeSort(LineStorage &LineStorage) {//unfinished
    return;
}