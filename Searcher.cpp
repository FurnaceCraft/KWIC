//
// Created by GKurf on 2022/6/3.
//

#include "Searcher.h"
Searcher::Searcher(int selectedStrategy)
{
    switch (selectedStrategy) {
        case 1:{
            strategy=new KMPSearch;
            break;
        }
        case 2:{
            strategy=new ViolentSearch;
            break;
        }
        /*default:{
            cout<<"Error Creating Searcher!"<<endl;
            system("pause");
            exit(0);
        }*/
    }
    //cout<<"Searcher Created Successfully!"<<endl;
}
vector<string> Searcher::doSearch(LineStorage &LineStorage) {
    return strategy->makeSearch(LineStorage,toSearch);;
}
void Searcher::insertWords(vector<string> inputWords) {
    toSearch.assign(inputWords.begin(),inputWords.end());
}
bool ifEqual(const char A, const char B)
{
    if (A == B|| abs(A-B)=='a'-'A')
    {
        return true;
    }
    return false;
}
void KMPSearch::calcNext(string pattern) {
    next.assign(pattern.size(),-1);
    int j = -1;
    for(int i = 1; i < static_cast<int>(pattern.size()); i++)
    {
        while(j != -1 && !ifEqual(pattern[j + 1],pattern[i]))
        {
            j = next[j];
        }
        if(ifEqual(pattern[j + 1],pattern[i]))
        {
            j++;
        }
        next[i] = j;
    }
}

bool KMPSearch::searchWord(string S, string P) {
    calcNext(P);
    //next.assign(100,-1);
    int lengthS = static_cast<int>(S.size());
    int lengthP = static_cast<int>(P.size());
    int j = 0;
    for(int i = 0; i < lengthS; i++)
    {
        while(j > 0 && i > 0 && !ifEqual(S[i],P[j]))
        {
            j = next[j - 1] + 1;
        }

        if(ifEqual(S[i],P[j]))
        {
            ++j;
        }
        if(j == lengthP&&(lengthS==i+1||S[i+1]==' '))
        {
            return true;
        }
    }
    return false;

}
vector<string> SearchStrategy::makeSearch(LineStorage &LineStorage,vector<string> toSearch) {
    int mark=0,mark2=0;
    vector<string> tmp(LineStorage.getConnectedLines());
    vector<string> foundLines{};
    /*for(auto it=tmp.begin();it!=tmp.end();++it){
        mark=0;
        for (auto it2 = toSearch.begin();it2!=toSearch.end();++it2) {
            if(!searchWord(*it,*it2))mark=1;
        }
        if (mark==0){
            mark2=1;
            //cout<<"Found: "<<*it<<endl;
            foundLines.push_back(*it);
        }
    }*/
    for(int i=0;i<tmp.size();i++){
        mark=0;
        for (int j=0;j<toSearch.size();j++) {
            if(!searchWord(tmp[i],toSearch[j]))mark=1;
        }
        if (mark==0){
            mark2=1;
            //cout<<"Found: "<<*it<<endl;
            foundLines.push_back(tmp[i]);
        }
    }
    if(mark2==0)
        //cout<<"No Qualified Line Found!"<<endl;
        foundLines.push_back("No Qualified Line Found!");
    return foundLines;
}
bool ViolentSearch::searchWord(string S, string P) {
    int i = 0,j=0;
    int lengthS = static_cast<int>(S.size());
    int lengthP = static_cast<int>(P.size());
    while (i < lengthS && j < lengthP) {
        if (ifEqual(S[i],P[j])) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == lengthP&&(lengthS==i||S[i]==' ')) {
        return true;
    } else {
        return false;
    }

}