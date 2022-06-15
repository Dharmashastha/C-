
#include<iostream>
#include "Rectangle.h"

using namespace std;

int main()
{
    
    Rectangle recCall1;
     cout << "Rectangle Values\n" + recCall1.print();
    int width=20;
    int height=15;
    int left=0;
    int top=0;
    Rectangle recCall2(width,height,left,top);
    cout << "\nRectangle Area Value is\n" + to_string(recCall2.findArea());
    cout << "\nRectangle Values\n" + recCall2.print();

    int width1 = 22;
    int height1 = 18;
    int left1 = 10;
    int top1 = 12;

    Rectangle recCall3(width1,height1,left1,top1);
    cout << "\nRectangle Area Value is\n" + to_string(recCall3.findArea());
    cout << "\nRectangle Values\n" +  recCall3.print();

    float wid=12.7f;
    float heig=15.2f;
    float lef=9.8f;
    float topd=10.4f;

    Rectangle recCall4(wid,heig,lef,topd);

    int width2 = recCall4.getWidth();
    int height2 = recCall4.getHeight();
    int left2 = recCall4.getLeft();
    int top2 = recCall4.getTop();
    
    cout << "\nRectangle Area Value is\n" + to_string(recCall4.findArea());
    cout << "\nRectangle Values\n" +  recCall4.print();

    Rectangle recCall5(recCall3);
    cout << "\nRectangle Area Value is\n" + to_string(recCall5.findArea());
    cout << "\nRectangle Values\n" + recCall5.print();

    int area = 30;
    Rectangle recCall6(recCall2,area);
    cout << "\nRectangle Area Value is\n" + to_string(recCall6.findArea());
    cout << "\nRectangle Values\n" + recCall6.print();

    return 0;
}