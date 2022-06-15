#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Rectangle
{
private:

    int *left;              //Attributes left,top,width,height,area,savedWidth,savedheight,savedleft,savedleft,savedtop
    int *top;
    int *width;
    int *height;
    int *area;
    int savedWidth;
    int savedHeight;
    int savedLeft;
    int savedTop;

public:
    Rectangle()            //Default constuctor
    {
        int dummy = 0;
        left = &dummy;
        top = &dummy;
        width = &dummy;
        height = &dummy;
    }

    Rectangle(Rectangle &recCall)   //Copy constuctor
    {
        this->width = recCall.width;
        this->height = recCall.height;
        this->left = recCall.left;
        this->top = recCall.top;
    }

    Rectangle(Rectangle &recCall, int area) //parameter copy object,int data variable
    {
        this->width = recCall.width;
        this->height = recCall.height;
        this->left = recCall.left;
        this->top = recCall.top;
        this->area = &area;
    }

    Rectangle(int &width, int &height, int &left, int &top)     //parameter full datatype int 
    {
        this->width = &width;
        this->height = &height;
        this->left = &left;
        this->top = &top;
    }

    ~Rectangle()
    {
        left = NULL;
        top = NULL;
        width = NULL;
        height = NULL;
        area = NULL;
        delete left;
        delete top;
        delete width;
        delete height;
        delete area;
    }

    Rectangle(float &width, float &height, float &left, float &top)     //parameter full datatype float
    {
        savedWidth = (int)round(width);
        savedHeight = (int)round(height);
        savedLeft = (int)round(left);
        savedTop = (int)round(top);
        this->width = &savedWidth;
        this->height = &savedHeight;
        this->left = &savedLeft;
        this->top = &savedTop;
    }

    int findArea()                                                  //Find Area
    {
        return (*width) * (*height);
    }

    int getWidth()
    {
        return savedWidth;
    }

    int getHeight()
    {
        return savedHeight;
    }

    int getLeft()
    {
        return savedLeft;
    }

    int getTop()
    {
        return savedTop;
    }

    string print()                              //Print All Values 
    {
        return "Width : " + to_string(*width) + "\nHeight : " + to_string(*height) + "\nLeft : " + to_string(*left) + "\nTop : " + to_string(*top);
    }
};
#endif
