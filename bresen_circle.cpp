#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

void mid_circle(int r, int xc, int yc){
    int x=0,y=r;
    int dp = 3-2r;
    while(x<=y){
        if(dp>=0){
            dp += 4*(x-y)+10;
            x++;
            y--;
        } else if(dp<0){
            dp += 4*(x) + 6;
            x++;
        }
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
        putpixel(xc+y,yc+x,WHITE);
        putpixel(xc+y,yc-x,WHITE);
        putpixel(xc-y,yc+x,WHITE);
        putpixel(xc-y,yc-x,WHITE);
    } 
}

int main(){
    int gd = DETECT, gm;
    int r,xc,yc;
    cout<<"Enter r,xc,yc: ";
    cin>>r>>xc>>yc;
    initgraph(&gd,&gm,NULL);
    mid_circle(r,xc,yc);
    getch();
    closegraph();

    return 0;
}