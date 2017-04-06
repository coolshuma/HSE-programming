#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class ComplexNumber {
private:
    T a, b;
public:
    ComplexNumber(const T& num_a = 0, const T& num_b = 0) : a(num_a), b(num_b) {
    }

    ComplexNumber& operator += (const ComplexNumber& other) { // потому что возвращаем сам элемент
        a += other.a;
        b += other.b;
        return *this;
    }

    ComplexNumber operator +(const ComplexNumber& other) const {
        ComplexNumber C(*this);
        C += other;
        return C;
    }

    ComplexNumber& operator -= (const ComplexNumber& other) {
        a -= other.a;
        b -= other.b;
        return *this;
    }

    ComplexNumber operator - (const ComplexNumber& other) const {
        ComplexNumber C(*this);
        C -= other;
        return C;
    }

    ComplexNumber& operator *= (const ComplexNumber& other) {
        a = a * other.a - b * other.b;
        b = a * other.b + other.a * b;
        return *this;
    }

    ComplexNumber operator *(const ComplexNumber& other) const {
        ComplexNumber C(*this);
        C *= other;
        return C;
    }

    ComplexNumber& operator /= (const ComplexNumber& other) {
        T sqr = other.abs() * other.abs();
        a = (a * other.a + b * other.b) / sqr;
        b = (a * other.b - other.a * b) / sqr;
        return *this;
    }

    ComplexNumber operator /(const ComplexNumber& other) const {
        ComplexNumber C(*this);
        C /= other;
        return C;
    }

    ComplexNumber operator +() const {
        ComplexNumber C(*this);
        return C;
    }

    ComplexNumber operator -() const {
        ComplexNumber C(*this);
        C.a = -a;
        C.b = -b;
        return C;
    }

    T abs() const {
        return sqrt(a * a + b * b);
    }

    T Re() const {
        return a;
    }

    T Im() const {
        return b;
    }

    bool operator == (const ComplexNumber& other) const {
            if ((a == other.a) && (b == other.b)) {
            return true;
        } else {
            return false;
        }
    }

    bool operator != (const ComplexNumber& other) const {
        if ((a == other.a) && (b == other.b)) {
            return false;
        } else {
            return true;
        }
    }
};

template <typename T>
ostream& operator << (ostream& os, const ComplexNumber<T>& c) {
    os << c.Re();
    if (c.Im() >= 0)
        os << '+';
    os << c.Im() << 'i' << endl;
    return os;
}

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int a1, a2, b1, b2;

    cin >> a1 >> a2 >>  b1 >> b2;

    ComplexNumber<int> a (a1, a2);
    ComplexNumber<int> b (b1, b2);

    cout << a << b;

    a += b;

    cout << a << b;

    a *= b;

    cout << a;

    a /= b;

    cout << a;

    ComplexNumber<int> c = a;
    cout << a << c;

    return 0;
}



