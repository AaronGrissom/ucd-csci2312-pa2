# include <cmath>
# include <iostream>

using namespace std;

# include "Point.h"

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
        if (this != &rPoint && this->getDims() == rPoint.getDims())
        {
            for (int i = 0; i < this->getDims(); i++)
            this->setValue(i,rPoint.getValue(i));
        }
        return *this;
    }

    Point::~Point()
    {
        delete [] __values;
    }
    
// Functions

    // double Point::distanceTo(const Point& nextPoint) const
    // {
    //     if (__dim > nextPoint.getDims())
    //     {
    //         Point temp(__dim);
    //     }
    // }
    
// Overloaded opperators

// Members
    // Point &operator*=(double); // p *= 6; p.operator*=(6);
    // Point &operator/=(double);
    // const Point operator*(double) const; // prevent (p1 * 2) = p2;
    // const Point operator/(double) const; // p3 = p2 / 2;

    // double &operator[](int index);

// Friends
    // friend Point &operator+=(Point &, const Point &);
    // friend Point &operator-=(Point &, const Point &);
    // friend const Point operator+(const Point &, const Point &);
    // friend const Point operator-(const Point &, const Point &);

    // friend bool operator==(const Point &, const Point &);
    // friend bool operator!=(const Point &, const Point &);

    // friend bool operator<(const Point &, const Point &);
    // friend bool operator>(const Point &, const Point &);
    // friend bool operator<=(const Point &, const Point &);
    // friend bool operator>=(const Point &, const Point &);

    // friend std::ostream &operator<<(std::ostream &, const Point &);
    // friend std::istream &operator>>(std::istream &, Point &);

    
    
    
    
    
    
    
    