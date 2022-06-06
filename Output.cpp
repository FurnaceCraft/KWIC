//
// Created by GKurf on 2022/6/3.
//

#include "Output.h"
Output::Output() {
    //cout<<"Output Created Successfully!"<<endl;
}
string beUpper(string str){
    string str2;
    str2.assign(str.begin(),str.end());
    str2[0]= toupper(str2[0]);
    return  str2;
}
void Output::showUpperConnectedLines(LineStorage LineStorage) {
    vector<string> tmp(LineStorage.getConnectedLines());
    for(auto it = tmp.begin();it!=tmp.end();++it){
        cout<<beUpper(*it)<<endl;
    }
    return;
}
void Output::showLines(vector<string> toShow) {
    vector<string> tmp=toShow;
    for(auto it = tmp.begin();it!=tmp.end();++it){
        cout<<*it<<endl;
    }
    return;
}