//
//  C8-1.cpp
//  
//
//  Created by 郑彤 on 2018/9/6.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Complex{
public:
    Complex(double r = 0.0, double i = 0.0): real(r), imag(i) {};
    Complex operator+ (const Complex &c2) const;
    Complex operator- (const Complex &c2) const;
    
    /*实现下面三个函数*/
    Complex operator* (const Complex &c2) const;
    Complex operator/ (const Complex &c2) const;
    friend ostream & operator<< (ostream &out, const Complex &c);
    
private:
    double real;
    double imag;
};

Complex Complex::operator+ (const Complex &c2) const {
    return Complex(real + c2.real, imag + c2.imag);
}

Complex Complex::operator- (const Complex &c2) const {
    return Complex(real - c2.real, imag - c2.imag);
}

Complex Complex::operator* (const Complex &c2) const {
    return Complex(real*c2.real-imag*c2.imag,real*c2.imag+imag*c2.real);
}

Complex Complex::operator/ (const Complex &c2) const {
    double a,b,c;
    a = real*c2.real + imag*c2.imag;
    b = imag * c2.real - real * c2.imag;
    c = c2.real*c2.real + c2.imag*c2.imag;
    return Complex(a/c,b/c);
}

ostream& operator<< (ostream &out, const Complex &c) {
    out << c.real << " " << c.imag << endl;
    return out;
}

int main() {
    double real, imag;
    cin >> real >> imag;
    Complex c1(real, imag);
    cin >> real >> imag;
    Complex c2(real, imag);
    cout << c1 + c2;
    cout << c1 - c2;
    cout << c1 * c2;
    cout << c1 / c2;
}
