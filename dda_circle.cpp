#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

void dda_circle(int r, int xc, int yc){
    float xc1 = r, yc1 = 0, sx = xc1, sy = yc1;
    int n = 0, mul = 1;
    while(mul<r){
        n++;
        mul *= 2;
    }
    float e = pow(2,-n);
    do{
        float xc2, yc2;
        xc2 = xc1 + (e*yc1);
        yc2 = yc1 - (e*xc1);
        putpixel(xc+round(xc2),yc-round(yc2),WHITE);
        xc1 = xc2;
        yc1 = yc2;
    }while(abs((yc1-sy)>=e) || abs((sx-xc1)>=e));
    
}

int main(){
    int gd = DETECT, gm;
    int r,xc,yc;
    cout<<"Enter r, xc, yc: ";
    cin>>r>>xc>>yc;
    initgraph(&gd,&gm,NULL);
    dda_circle(r,xc,yc);
    getch();
    closegraph();

    return 0;
}