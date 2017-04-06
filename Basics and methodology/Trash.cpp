
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    vector <int> v{1, 2, 3};
    vector <int> u{0, 0, 0, 1, 2, 3, 4, 0, 0, 0};
    Polynomial<int> b = v;

    Polynomial<int> a = u;

    cout << a << endl << b << endl;

    cout << (4 != a) << endl;

    cout << a << endl;

    cout << a[0] << endl;

    cout << a.Degree() << endl;

    Polynomial<int> t(v);

    for (auto it = a.begin(); it != a.end(); ++it)
        cout << *it << ' ';

    cout << endl;

    a = t;

    vector<int> v1{3, 2, 2};
    vector<int> u1{2, 3};

    Polynomial<int> c(v1);
    Polynomial<int> d(u1);

    c *= d;

    cout << c << endl;

    v = {1, -1, 2, -2};
    u = {1, 0};
    vector<int> v2{4};

    Polynomial<int> t1(v);
    Polynomial<int> t2(u);

    t2 -= t1;

    cout << t2 << endl;

    cout << (t1 == t2) << ' ' << (t1 != t2) << ' ' << (t1 == 4) << ' ' << (4 == t1) << endl;

    Polynomial<int> b1(v), b2(v), b3(v2);

    cout << (b1 == b2) << ' ' << (b1 == b3) << ' ' << (b3 == 4) << ' ' << (4 == b3) << endl;

    Polynomial<int> em;

    cout << em << ' ' << em.Degree() << endl;

    em = em + t1;

    cout << em << ' ' << em.Degree() << endl;

    cout << em(1) << endl;

    for (int i = 0; i < 10; ++i) {
        cout << em[i] << ' ';
    }

    cout << endl;

    Polynomial<int> one(3);

    cout << one.Degree() << endl;

    return 0;
}



int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    vector<int> v{2, 3}, u{3, 2, 2};
    Polynomial<int> a(v);
    Polynomial<int> b(u);
    Polynomial<int> c(0);

    cout << a << endl;

    cout << c(999) << endl;

    b = b * a;

    cout << a;

    return 0;
}

template <typename T>
Polynomial<T> operator*=(const Polynomial<T>& a, const T& b)  {
    Polynomial<T> b(v);
    a *= b;
    return a;
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    vector<int> v{-1, -1}, u{0, 1};
    Polynomial<int> a(v);
    Polynomial<int> b(u);
    Polynomial<int> c(0);

    cout << a << endl;

    cout << c(999) << endl;

    cout << b << endl;

    a = a * 4;

    cout << a;
    return 0;
}

template <typename T>
ostream& operator << (ostream& os, const Polynomial<T>& my_polynom) {
    for (int i = my_polynom.Degree(); i >= -1;  --i) {
        if (my_polynom[i] == 0)
            continue;

        if (my_polynom[i] == -1) {
            os << "-";
        } else if (my_polynom[i] > -1 && i != my_polynom.Degree()) {
            os << "+";
        }

        if (my_polynom[i] != 1 && my_polynom[i] != -1) {
            os << my_polynom[i];
            if (i > 0)
                os << '*';
        }

        if (i > 0)
            os << "x";

        if (i > 1)
            os << "^" << i;

        if (i == 0 && (my_polynom[i] == 1 || my_polynom[i] == -1))
            os << 1;
    }
    return os;
}

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Polynomial {
private:
    vector<T> coefficients;
public:
    Polynomial(vector<T> my_vector) : coefficients(my_vector) {}
    Polynomial(const T& coefficient) {
        coefficients.push_back(coefficient);
    }
    template <typename InputIterator>
    Polynomial(InputIterator begin, InputIterator end) : coefficients(begin, end) {}

    void erase_zeroes() {
        while(!coefficients.empty() && *coefficients.back() == T())
            coefficients
    }
};



int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    vector <int> v{1, 2, 3};
    vector <int> u{0, 0, 0, 1, 2, 3, 4, 0, 0, 0};
    Polynomial<int> b = v;

    Polynomial<int> a = u;

    cout << a << endl << b << endl;

    cout << (4 != a) << endl;

    cout << a << endl;

    cout << a[0] << endl;

    cout << a.Degree() << endl;

    Polynomial<int> t(v);

    for (auto it = a.begin(); it != a.end(); ++it)
        cout << *it << ' ';

    cout << endl;

    a = t;

    vector<int> v1{3, 2, 2};
    vector<int> u1{2, 3};

    Polynomial<int> c(v1);
    Polynomial<int> d(u1);

    cout << c << endl;

    v = {1, -1, 2, -2};
    u = {1, 0};
    vector<int> v2{4};

    Polynomial<int> t1(v);
    Polynomial<int> t2(u);

    t2 -= t1;

    cout << t2 << endl;

    cout << (t1 == t2) << ' ' << (t1 != t2) << ' ' << (t1 == 4) << ' ' << (4 == t1) << endl;

    Polynomial<int> b1(v), b2(v), b3(v2);

    cout << (b1 == b2) << ' ' << (b1 == b3) << ' ' << (b3 == 4) << ' ' << (4 == b3) << endl;

    Polynomial<int> em(0);

    cout << em << ' ' << em.Degree() << endl;

    em = em + t1;

    cout << em << ' ' << em.Degree() << endl;

    for (int i = 0; i < 10; ++i) {
        int x = em[i];
        cout << x << ' ';
    }

    cout << endl;

    Polynomial<int> one(3);

    cout << one.Degree() << endl;

    return 0;
}