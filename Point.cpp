# include "Point.h"
# include <iostream>

using namespace std;
using namespace Clustering;

// constructors
    Point::Point(int num)
    {
        __values = nullptr;
        __dim = num;
    
        __values = new double[__dim];
        for (int i = 0; i < __dim; ++i)
        __values[i]=0;
    }
    
// Accessors & mutators
    int Point::getId() const
    {
        return __id;
    }
    int Point::getDims() const
    {
        return __dim;
    }
    void Point::setValue(int num, double val)
    {
        __values[num] = val;
    }
    double Point::getValue(int num) const
    {
        return __values[num];
    }

// Big three: cpy ctor, overloaded operator=, dtor

    // Point::Point(const Point &CpydPoint)
    // {
        
    // }
    
    // Point::Point &operator=(const Point &)
    // {
        
    // }

    Point::~Point()
    {
        delete [] __values;
    }