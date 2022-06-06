//
// Created by GKurf on 2022/6/3.
//

#include "Graphics.h"
void Graphics::drawLine() {
    for(int i=0;i<30;i++)cout<<"-";
    cout<<endl;
}
void Graphics::welcome() {
    cout<<"Welcome to KWIC system!"<<endl;
    drawLine();
}
Graphics::Graphics() {
    //cout<<"Graphics Created Successfully!"<<endl;
}
