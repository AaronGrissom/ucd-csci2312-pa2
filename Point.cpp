# include "Point.h"
# include <iostream>

using namespace std;
using namespace Clustering;

// constructors
    Point::Point(int num
    {
        __values = nullptr;
        __dim = num;
    
        __values = new double[__dim];
        for (int i = 0; i < __dim; ++i)
        __values[i]=0;
    }

    Point::Point(int num, double* ptr)
    {
        __dim = num;
    
        for (int i = 0; i < __dim; ++i)
        __values[i] = ptr [i];
    }

// Big three: cpy ctor, overloaded operator=, dtor



    Point::~Point()
    {
        delete [] __values;
        __values = nullptr;
    }