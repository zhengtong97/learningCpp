//
//  C7-3.cpp
//  
//
//  Created by 郑彤 on 2018/9/5.
//

#include <iostream>
using namespace std;

struct Base1
{
    int x;
    Base1(int x):x(x){}
};

struct Base2
{
    int x;
    Base2(int x):x(x){}
};

struct Derived:public Base1, public Base2
{
    int x;
    Derived(Base1& a, Base2& b):Base1(a),Base2(b){x = Base1::x + Base2::x;}
};

//请实现Base1，Base2, Derived的构造函数


int main()
{
    int x, y;
    cin >> x >> y;
    Base1 a(x);
    Base2 b(y);
    Derived d(a, b);
    cout << d.Base1::x << "+" << d.Base2::x << "=" << d.x << endl;
    return 0;
}
