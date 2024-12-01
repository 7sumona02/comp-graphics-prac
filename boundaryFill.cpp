#include <graphics.h>
#include <iostream>
using namespace std;

void boundaryfill(int x, int y, int b, int n){
    if(getpixel(x,y)!==b && getpixel(x,y)!==n){
        putpixel(x,y,n);
        boundaryfill(x+1,y,b,n);
        boundaryfill(x-1,y,b,n);
        boundaryfill(x,y+1,b,n);
        boundaryfill(x,y-1,b,n);
    }
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);
    line(100,100,50,400);
    line(100,100,150,400);
    line(50,400,100,200);
    line(150,400,100,200);
    boundaryfill(100,150,WHITE,14);
    getch();
    closegraph();

    return 0;
}