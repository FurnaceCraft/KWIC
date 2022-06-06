//
// Created by GKurf on 2022/6/1.
//

#include "Shifter.h"
#include <algorithm>
Shifter::Shifter() {
    //cout<<"Shifter Created Successfully!"<<endl;
}
void Shifter::makeShift(LineStorage &LineStorage) {
    vector<string> tmpWordLine{};
    vector<vector<string>> originalWordLine=LineStorage.getWordLines();
    //originalWordLine.assign(LineStorage.getWordLines().begin(),LineStorage.getWordLines().end());
    string tmpString{};
    int shiftsToGO=LineStorage.getNumberOfLines(),rotatesToGo;
    for(int j=0;j<shiftsToGO;j++){

        rotatesToGo=originalWordLine[j].size()-1;
        for(int i=0;i<rotatesToGo;i++){
            tmpWordLine.assign(originalWordLine[j].begin(),originalWordLine[j].end());
            rotate(tmpWordLine.begin(),tmpWordLine.begin()+i+1,tmpWordLine.end());
            LineStorage.pushBackWordLines(tmpWordLine);
            for(auto it=tmpWordLine.begin();it!=tmpWordLine.end();++it){
                if (next(it)!=tmpWordLine.end()){
                    tmpString+=*it;
                    tmpString+=" ";
                }
                else{
                    tmpString+=*it;
                }
            }
            LineStorage.pushBackConnectedLines(tmpString);
            tmpString.clear();
            tmpWordLine.clear();
        }
    }
    return;
}