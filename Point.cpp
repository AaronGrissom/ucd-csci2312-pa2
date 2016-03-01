# include "Point.h"
# include <iostream>

using namespace std;
using namespace Clustering;


// constructors
    unsigned int Point::__idGen = 0;
    Point::Point(int num)
    {
        __id = __idGen++;
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

    Point::Point(const Point &CpydPoint)
    {
        __id = CpydPoint.getId();
        __dim = CpydPoint.getDims();
        __values = new double[__dim];
    
        for (int i = 0; i < __dim; ++i)
        __values[i]=CpydPoint.getValue(i);
    }
    
    Point &Point::operator=(const Point &rPoint)
    {
        Point lPoint(rPoint.getDims());
        lPoint.__id = rPoint.getId();
        lPoint.__values = new double[lPoint.__dim];
    
        for (int i = 0; i < lPoint.__dim; ++i)
        lPoint.__values[i]=rPoint.getValue(i);
        
        cout << "Point L:" << endl;
        cout << "\tID: " << lPoint.getId() << endl;
        cout << "\tDimentions: " << lPoint.getDims() << endl;
        cout << "\tValues: |";
        for (int i = 0; i < 5; i++)
            cout << lPoint.getValue(i) << "|";
        cout << endl;
        
        return lPoint;
    }

    Point::~Point()
    {
        delete [] __values;
    }