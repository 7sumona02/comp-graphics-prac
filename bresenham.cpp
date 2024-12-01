#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

void bresenham(int x1, int y1, int x2, int y2){
    int dx, dy, dp, xi, yi;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    dp = (2*dy)-dx;
    xi = x1, yi = y1;
    putpixel(xi,yi,WHITE);
    for(int i=0; i<dx; i++){
        if(dp<0)
            {
                putpixel(xi, yi, WHITE);
                dp = dp + (2*dy);
                xi += 1;
                delay(100);
            }
        else if(dp>=0)
            {
                putpixel(xi,yi,WHITE);
                dp = dp + (2*dy) - (2*dx);
                xi += 1;
                yi += 1;
                delay(100);
            }
    }
}

int main(){
    int gd = DETECT, gm;
    int x1,y1,x2,y2;
    cout<<"Enter x1,y1: ";
    cin>>x1>>y1;

    cout<<"Enter x2,y2: ";
    cin>>x2>>y2;

    initgraph(&gd,&gm,NULL);
    bresenham(x1,y1,x2,y2);
    getch();
    closegraph();

    return 0;
}