#include <iostream>

class A {
private: 

public:
    int x;
    int* y;

    A(const A& a) {
        this->x = a.x;
        this->y = new int;
        *this->y = *a.y;
    }

/*
    A(A* a) {
    this->x = a->x;
    this->y = new int;
    *this->y = *a->y;
    }
*/


    A(int x, int* y)
    {
        this->x = x;
        this->y = y;
    }
    int getX()
    {
        return x;
    }
    void setX(int _x)
    {
        x = _x;
    }
};

int main()
{
    A a1(5, new int(7));
    A a2(a1);
    *a1.y = 12;
    std::cout << a2.getX();
}
