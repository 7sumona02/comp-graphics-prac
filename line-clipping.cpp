#include <graphics.h>
#include <iostream>
using namespace std;

int main(){
    int gd = DETECT, gm;
    int X1,Y1,X2,Y2;
    cout<<"Enter X1,Y1,X2,Y2 (clipping window): ";
    cin>>X1>>Y1>>X2>>Y2;

    int x1,y1,x2,y2;
    cout<<"Enter x1,y1,x2,y2 (line): ";
    cin>>x1>>y1>>x2>>y2;

    int op[2][4]; //[0,1,2,3]
    if(x1<X1)
    //L=1
        op[0][3]=1;
    else
    //L=0
        op[0][3]=0;
    if(x1>X2)
    //R=1
        op[0][2]=1;
    else
    //R=0
        op[0][2]=0;
    if(y1<Y1)
    //T=1
        op[0][0]=1;
    else
    //T=0
        op[0][0]=0;
    if(y1>Y2)
    //B=1
        op[0][1]=1;
    else
    //B=0
        op[0][1]=0;
    

    if(x2<X1)
    //L=1
        op[0][3]=1;
    else
    //L=0
        op[0][3]=0;
    if(x2>X2)
    //R=1
        op[0][2]=1;
    else
    //R=0
        op[0][2]=0;
    if(y2<Y1)
    //T=1
        op[0][0]=1;
    else
    //T=0
        op[0][0]=0;
    if(y2>Y2)
    //B=1
        op[0][1]=1;
    else
    //B=0
        op[0][1]=0;

    cout<<op[0][0]<<op[0][1]<<op[0][2]<<op[0][3]<<endl;
    cout<<op[1][0]<<op[1][1]<<op[1][2]<<op[1][3]<<endl;
    initgraph(&gd,&gm,NULL);
    outtextxy(100,100,"Before Clipping");
    rectangle(X1,Y1,X2,Y2);
    line(x1,y1,x2,y2);
    getch();
    closegraph();
    cleardevice();
    float m = (y2-y1)/(x2-x1);

    if(!(op[0][0]==0 && op[0][1]==0 op[0][2]==0 && op[0][3]==0 && op[1][0]==0 && op[1][1]==0 op[1][2]==0 && op[1][3]==0)){
        if(((op[0][0] && op[1][0])==0) && ((op[0][1] && op[1][1])==0) && ((op[0][2] && op[1][2])==0) && ((op[0][3] && op[1][3])==0)){
            if(op[0][1]==1){
                x1 = x1 + (Y1-y1)/m;
            }
            if(op[1][1]==1){
                x2 = x2 + (Y1-y2)/m;
            }
        }
        else{
            x1=y1=x2=y2=0;
        }
    }
    initgraph(&gd,&gm,NULL);
    outtextxy(100,100,"After Clipping");
    rectangle(X1,Y1,X2,Y2);
    line(x1,y1,x2,y2);
    getch();
    closegraph();

    return 0;
}
