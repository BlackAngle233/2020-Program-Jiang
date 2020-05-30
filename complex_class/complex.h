#include <iostream>
using namespace std;


class complex
{
    double r;
    double i;
    
    public:
    complex()
    {
        r = 0;
        i = 0;
    }
    complex(double a,double b)
    {
        r = a;
        i = b;
    }
    double getImag();
    double getReal();
    friend complex operator +(const complex &c1, const complex &c2);
	friend complex operator -(const complex &c1, const complex &c2);
	friend complex operator * (const complex& c1,const complex &c2);
	friend complex operator / (const complex& c1, const complex &c2);
	friend complex operator -(const complex &c);
    friend ostream &operator<<(std::ostream &os, const complex &c);
};

complex operator +(const complex &c1, const complex &c2)
{
    return complex(c1.r + c2.r,c1.i + c2.i);
}

complex operator -(const complex &c1, const complex &c2)
{
    return complex(c1.r - c2.r,c1.i + c2.i);
}

complex operator * (const complex &c1, const complex &c2)
{
    return complex(c1.r * c2.r - c1.i * c2.i,c1.r * c2.i + c1.i * c2.r);
}

complex operator / (const complex &c1, const complex &c2)
{
    return complex((c1.r * c2.r + c1.i * c2.i) / (c2.r * c2.r + c2.i * c2.i), (c1.i * c2.r - c1.r * c2.i) / (c2.r * c2.r + c2.i * c2.i));
}

complex operator -(const complex &c)
{
    return complex(-c.r, -c.i);
}

std::ostream& operator<<(std::ostream& os, const complex &c)
{
    if(c.i>0)
	    os << c.r <<"+"<<c.i<<"i";
    else if(c.i<0)
        os << c.r << "+(" << c.i << ")i";
    else
        os << c.r;
    return os;
}