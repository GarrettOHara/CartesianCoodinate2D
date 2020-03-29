#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    float x,y;
    float getX()
    {
        return x;
    }
    float getY()
    {
        return y;
    }
    void setX(float X)
    {
        x = X;
    }
    void setY(float Y)
    {
        y = Y;
    }
public:
    void print()
    {
        cout << x << ", " << y << endl;
    }
    Point() = delete;
    // Point()
    // {
    //     x = 0.0f;
    //     y = 0.0f;
    //     cout << "\nPlease provide two arguments for the point in order to 
    //              create a valid point object" << endl;
    // }
    Point(float X, float Y)
    {
        x = X;
        y = Y;
    }
    ~Point()
    {
        //cout<< "object destroyed" << endl;
    }
    friend bool operator < (Point const a, Point const b);
    friend bool operator > (Point const x, Point const y);
    friend bool operator >= (Point const x, Point const y);
    friend bool operator <= (Point const x, Point const y);
    friend bool operator == (Point const x, Point const y);
    friend bool operator != (Point const x, Point const y);

    float distance(Point a)
    {
        float distance = 0.0f;
        double x = pow(a.getX(),2);
        double y = pow(a.getY(),2);
        distance = (float) sqrt(x + y);
        return distance;
    }
    bool lessThan(Point a, Point b)
    {
        if ( (a.distance(a)) < (b.distance(b)) )
            return true;
        else
            return false;
    }
    bool greaterThan(Point a, Point b)
    {
        if( (a.lessThan(a,b) == false) && (a.lessThan(b,a) == true))
            return true;
        else
            return false;
    }
    bool equalTo(Point a, Point b)
    {
        if ( a.lessThan(a,b) == true)
            return false;
        else if ( a.lessThan(b,a) == true)
            return false;
        else
            return true;
    }
    bool notEqualTo(Point a, Point b)
    {
        if ( (a.lessThan(a,b) || (a.lessThan(b,a)) == true))
            return true;
        else
            return false;
    }
    bool greaterThanEqual(Point a, Point b)
    {
        if( ((a.lessThan(a,b)==false) && (a.lessThan(b,a)==true)) 
            || ((a.lessThan(a,b)==false) && (a.lessThan(b,a)==false)) )
            return true;
        else
            return false;
    }
    bool lessThanEqual(Point a, Point b)
    {
        if( ((a.lessThan(a,b)==true) && (a.lessThan(b,a)==false)) 
            || ((a.lessThan(a,b)==false) && (a.lessThan(b,a)==false)) )
            return true;
        else
            return false;
    }
};
bool operator < (Point a, Point b)
    {
        if ( (a.distance(a)) < (b.distance(b)) )
            return true;
        else
            return false;
    }
bool operator > (Point a, Point b)
{
    if( (a.lessThan(a,b) == false) && (a.lessThan(b,a) == true))
            return true;
        else
            return false;
}
bool operator == (Point a, Point b)
{
    if ( a.lessThan(a,b) == true)
            return false;
        else if ( a.lessThan(b,a) == true)
            return false;
        else
            return true;
}
bool operator != (Point a, Point b)
{
    if ( (a.lessThan(a,b) || (a.lessThan(b,a)) == true))
            return true;
        else
            return false;
}
bool operator >= (Point a, Point b)
{
    if( ((a.lessThan(a,b)==false) && (a.lessThan(b,a)==true)) 
            || ((a.lessThan(a,b)==false) && (a.lessThan(b,a)==false)) )
            return true;
        else
            return false;
}
bool operator <= (Point a, Point b)
{
    if( ((a.lessThan(a,b)==true) && (a.lessThan(b,a)==false)) 
            || ((a.lessThan(a,b)==false) && (a.lessThan(b,a)==false)) )
            return true;
        else
            return false;
}