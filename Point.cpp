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
        if (this != &rPoint)
        {
            if (this->getDims() == rPoint.getDims())
            {
                this->__dim = rPoint.getDims();
                for (int i = 0; i  < this->getDims(); ++i)
                    this->setValue(i,rPoint.getValue(i));
            }
            else
            {
                delete [] this->__values;
                this->__dim = rPoint.getDims();
                __values = new double[this->__dim];
                for (int i = 0; i  < this->getDims(); ++i)
                    this->setValue(i,rPoint.getValue(i));
            }
        }
    }

    Point::~Point()
    {
        delete [] __values;
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



// Functions
    double Point::distanceTo(const Point& nextPoint) const
    {
        double sum;
        
        if (this->getDims() == nextPoint.getDims())
        {
            double difference[nextPoint.getDims()];
            
            for (int i = 0; i < nextPoint.getDims(); i++)
            difference[i] = this->getValue(i) - nextPoint.getValue(i);  
        
            for (int i = 0; i < nextPoint.getDims(); i++)
            difference[i] = pow(difference[i],2);
        
            for (int i = 0; i < nextPoint.getDims(); i++)
            sum += difference[i];
        }
        
        else if (this->getDims() > nextPoint.getDims())
        {
            int counter = 0;
            double difference[this->getDims()];
            
            for (; counter < nextPoint.getDims(); counter++)
                difference[counter] = this->getValue(counter) - nextPoint.getValue(counter);
                
            for (; counter < this->getDims(); counter ++)
                difference[counter] = this->getValue(counter);
        
            for (int i = 0; i <this->getDims(); i++)
            difference[i] = pow(difference[i],2);
        
            for (int i = 0; i < this->getDims(); i++)
            sum += difference[i];
        }
        
        else
        {
            int counter = 0;
            double difference[nextPoint.getDims()];
            
            for (; counter < this->getDims(); counter++)
                difference[counter] = this->getValue(counter) - nextPoint.getValue(counter);
                
            for (; counter < nextPoint.getDims(); counter ++)
                difference[counter] = nextPoint.getValue(counter);
        
            for (int i = 0; i <nextPoint.getDims(); i++)
            difference[i] = pow(difference[i],2);
        
            for (int i = 0; i < nextPoint.getDims(); i++)
            sum += difference[i];
        }
        
        return sqrt(sum);
    }
    
// Overloaded opperators



// Members
    Point &Point::operator*=(double multiplier) // p *= 6; p.operator*=(6);
    {
         for (int i = 0; i < this->getDims(); i++)
             setValue(i,this->getValue(i) * multiplier);
    }
    
    Point &Point::operator/=(double divider)
    {
        for (int i = 0; i < this->getDims(); i++)
             setValue(i,this->getValue(i) / divider);
    }

    const Point Point::operator*(double multiplier) const // prevent (p1 * 2) = p2;
    {
        Point temp(this->getDims());
        temp = *this;
        temp *= multiplier;
        return temp;
    }
    const Point Point::operator/(double divider) const // p3 = p2 / 2;
    {
        Point temp(this->getDims());
        temp = *this;
        temp /= divider;
        return temp;
    }
    double &Point::operator[](int index)
    {
        Point mVector(1);
        return mVector[index];
    }
/*
// Friends
    Point &operator+=(Point & x, const Point & y)
    {
        
    }
    Point &operator-=(Point & x, const Point & y)
    {
        
    }
    const Point Point::operator+(const Point & x, const Point &y)
    {
        
    }
    const Point Point::operator-(const Point &x, const Point &y)
    {
        
    }

    bool Point::operator==(const Point &x, const Point &y)
    {
        
    }
    bool Point::operator!=(const Point &x, const Point &y)
    {
        
    }

    bool Point::operator<(const Point &x, const Point &y)
    {
        
    }
    bool Point::operator>(const Point &x, const Point &y)
    {
        
    }
    bool Point::operator<=(const Point &x, const Point &y)
    {
        
    }
    bool Point::operator>=(const Point &x, const Point &y)
    {
        
    }

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
    std::istream &operator>>(std::istream &x, Point &y)
    {
        
    }
*/
    
    
    
    
    
    
    
    