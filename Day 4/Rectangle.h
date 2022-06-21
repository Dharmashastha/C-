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
        left = (int*) malloc(1 * sizeof(int));
        if(left == NULL)
        {
            throw("Memory allocation failed.\n");
        }
        *left = 0;
        top = (int*) malloc(1 * sizeof(int));
        *top = 0;
        width = (int*) malloc(1 * sizeof(int));
        *width = 0;
        height = (int*) malloc(1 * sizeof(int));
        *height = 0;
    }

    Rectangle(Rectangle &recCall)   //Copy constuctor
    {
        width = (int*) malloc(1 * sizeof(int));
        *width = 24;
        height = (int*) malloc(1 * sizeof(int));
        *height = 28;
        left = (int*) malloc(1 * sizeof(int));
        *left = 12;
        top = (int*) malloc(1 * sizeof(int));
        *top = 20;
        area = (int*) malloc(1 * sizeof(int));
        *area = findArea();
    }

    Rectangle(int width1, int height1, int left1, int top1)     //parameter full datatype int 
    {
        width = (int*) malloc(1 * sizeof(int));
        *width = width1;
        height = (int*) malloc(1 * sizeof(int));
        *height = height1;
        left = (int*) malloc(1 * sizeof(int));
        *left = left1;
        top = (int*) malloc(1 * sizeof(int));
        *top = top1;
    }

    ~Rectangle()
    {
        delete left;
        delete top;
        delete width;
        delete height;
      //  delete area;
    }

    Rectangle(float width1, float height1, float left1, float top1)     //parameter full datatype float
    {
        savedWidth = (int)round(width1);
        savedHeight = (int)round(height1);
        savedLeft = (int)round(left1);
        savedTop = (int)round(top1);
        width = (int*) malloc(1 * sizeof(int));
        *width = savedWidth;
        height = (int*) malloc(1 * sizeof(int));
        *height = savedHeight;
        left = (int*) malloc(1 * sizeof(int));
        *left = savedLeft;
        top = (int*) malloc(1 * sizeof(int));
        *top = savedTop;
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
