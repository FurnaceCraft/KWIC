//
// Created by GKurf on 2022/6/1.
//

#include "Input.h"
#include <fstream>
#include <string>
using namespace std;
bool ifLegal(string A){
    if(A.size()==0)return false;
    for(int i=0;i<A.size();i++){
        if (isalpha(A[i])||A[i]==' '){
            continue;
        }
        cout<<"Invalid Input!";
        return false;
    }
    return true;
}
string readFilename(){
    string filename{};
    cout<<"Please Enter Filename Here:";
    cin>>filename;
    //cout<<endl;
    return filename;
}
vector<string> stringToVect(string str)
{
    vector<string> result{};
    int pos = str.find(" ", 0);
    int startPos = 0;
    int splitN = pos;
    string lineText(" ");
    while (pos > -1)
    {
        lineText = str.substr(startPos, splitN);
        startPos = pos + 1;
        pos = str.find(" ", pos + 1);
        splitN = pos - startPos;
        result.push_back(lineText);
    }
    lineText = str.substr(startPos, str.length() - startPos);
    result.push_back(lineText);
    return result;
}
void Input::readFile(LineStorage &LineStorage) {
    string line, word;
    fstream tmpfile;
    tmpfile.open(readFilename());
    //tmpfile.open("../"+readFilename());
    //tmpfile.open("../"+static_cast<string>("test.txt"));
    if (!tmpfile){
        cout << "No Such File!" << endl;
        system("pause");
        exit(0);
    }
    else {
        while (getline(tmpfile, line)) {
            if (!ifLegal(line)){
                cout<<"File Includes Illegal Characters!"<<endl;
                system("pause");
                exit(0);
            }
            //transform(line.begin(),line.end(),line.begin(),[](unsigned char c){ return tolower(c); });
            LineStorage.pushBackWordLines(stringToVect(line));
            LineStorage.pushBackConnectedLines(line);
        }
        tmpfile.close();
    }
    return;
}
void Input::readPattern(Searcher &Searcher) {
    vector<string> pattern{};
    string word="1";
    while (1){
        cout<<"Please Enter The First Word To Search(To Quit, Simply Input '1'):";
        cin>> word;
        if (word=="1"){
            exit(0);
        }
        if(ifLegal(word)){
            break;
        }
        cout<<"Pattern Includes Illegal Characters!"<<endl;
    }
    pattern.push_back(word);
    while (1){
        cout<<"Please Enter The Next Word To Search(To Finish Input, Simply Input '1'):";
        cin>>word;
        if (word=="1")break;
        if(ifLegal(word)){
            pattern.push_back(word);
        }
    }
    Searcher.insertWords(pattern);
    return;
}
int Input::readSearchStrategy() {
    int a=0;
    while (1){
        cout<<"Please Select A Searching Strategy('1' for KMPSearch and '2' for ViolentSearch):";
        cin>>a;
        if(a>=1&&a<=2)break;
        else {
            cout<<"Invalid Input!"<<endl;
            system("pause");
            exit(0);
        }

    }
    return  a;
}
Input::Input(){
    //cout<<"Input Created Successfully!"<<endl;
}