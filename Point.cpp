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
        int i = 0;
        
        if (this != &rPoint && this->getDims() == rPoint.getDims())
        {
            for (i = 0; i < this->getDims(); i++)
            this->setValue(i,rPoint.getValue(i));
            return *this;
        }
        else if (this != &rPoint && this->getDims() < rPoint.getDims())
        {
            cout << endl << "------------------------" << endl;
            cout << "ERROR! unable to assign due to demention missmatch" << endl;
            cout << "Point trying to copy assign:" << endl;
                cout << "\tID: " << this->getId() << endl;
                cout << "\tDimentions: " << this->getDims() << endl;
                cout << "\tValues: |";
                for (int i = 0; i < this->getDims(); i++)
                cout << this->getValue(i) << "|";
                cout << endl;
            cout << "Point getting value from:" << endl;
                cout << "\tID: " << rPoint.getId() << endl;
                cout << "\tDimentions: " << rPoint.getDims() << endl;
                cout << "\tValues: |";
                for (int i = 0; i < rPoint.getDims(); i++)
                cout << rPoint.getValue(i) << "|";
                cout << endl;
            cout << "------------------------" << endl;
        return *this;
        }
        else
        {
            for (i = 0; i < rPoint.getDims(); i++)
            this->setValue(i,rPoint.getValue(i));
            for (;i < rPoint.getDims(); i++)
            this->setValue(i,0);
            return *this;
        }
    }

    Point::~Point()
    {
        delete [] __values;
    }
    
// // Functions
//     double Point::distanceTo(const Point& nextPoint) const
//     {

//     }
    
// // Overloaded opperators

// // Members
//     Point &operator*=(double x) // p *= 6; p.operator*=(6);
//     {
        
//     }
//     Point &operator/=(double x)
//     {
        
//     }
//     const Point Point::operator*(double x) const // prevent (p1 * 2) = p2;
//     {
        
//     }
//     const Point Point::operator/(double x) const // p3 = p2 / 2;
//     {
        
//     }

//     double &operator[](int index)
//     {
        
//     }

// // Friends
//     Point &operator+=(Point & x, const Point & y)
//     {
        
//     }
//     Point &operator-=(Point & x, const Point & y)
//     {
        
//     }
//     const Point Point::operator+(const Point & x, const Point &y)
//     {
        
//     }
//     const Point Point::operator-(const Point &x, const Point &y)
//     {
        
//     }

//     bool Point::operator==(const Point &x, const Point &y)
//     {
        
//     }
//     bool Point::operator!=(const Point &x, const Point &y)
//     {
        
//     }

//     bool Point::operator<(const Point &x, const Point &y)
//     {
        
//     }
//     bool Point::operator>(const Point &x, const Point &y)
//     {
        
//     }
//     bool Point::operator<=(const Point &x, const Point &y)
//     {
        
//     }
//     bool Point::operator>=(const Point &x, const Point &y)
//     {
        
//     }

    std::ostream &operator<<(std::ostream &screen, const Point &__Point)
    {
        screen << "Point getting value from:" << endl;
        screen << "\tID: " << __Point.getId() << endl;
        screen << "\tDimentions: " << __Point.getDims() << endl;
        screen << "\tValues: |";
        for (int i = 0; i < __Point.getDims(); i++)
        screen << __Point.getValue(i) << "|";
        screen << endl;
    }
    // std::istream &operator>>(std::istream &x, Point &y)
    // {
        
    // }

    
    
    
    
    
    
    
    