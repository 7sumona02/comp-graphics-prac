#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

void dda(int x1, int y1, int x2, int y2){
    floor xi,yi,xn,yn,dx,dy,step;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx)>=abs(dy))
        step = abs(dx);
    else
        step = abs(dy);
    
    xi = dx/step;
    yi = dy/step;
    xn = x1;
    yn = y1;
    for(int i=1; i<=step; i++){
        putpixel(floor(xn),floor(yn),GREEN);
        xn += xi;
        yn += yi;
    }
}

int main(){
    int gd = DETECT, gm;
    int x1,y1,x2,y2;
    cout<<"Enter x1,y1,x2,y2: ";
    cin>>x1>>y1>>x2>>y2;

    initgraph(&gd,&gm,NULL);
    dda(x1,y1,x2,y2);
    getch();
    closegraph();

    return 0;
}