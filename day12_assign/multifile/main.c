#include<stdio.h>
#include "rectangle.h"
#include "square.h"
#include "circle.h"
int main()
{
    int radius= 10;
    area_circle(radius);
    

    int length =10 ;
    int breath = 10;
    area_rect(length , breath);

    int side =10;
    area_square(side);
}