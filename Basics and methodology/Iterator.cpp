/*#include <iostream>
#include <vector>

using std::vector;

template <typename T, int N>
class Matrix {
private:
    vector<vector<T>> data;
    // тут могут быть и другие реализации: например, фиксированный массив T[N][N], или одномерный массив размера N^2

public:
    Matrix(const vector<vector<T>>& d)
            : data(d) {
    }

    // Конструктор для скалярной матрицы
    Matrix(const T& value = 0) {
        data.resize(N);
        for (auto& row : data)
            row.resize(N);
        for (size_t i = 0; i != N; ++i)
            data[i][i] = value;
    }

    // Перегрузим оператор "круглые скобки" для получения элемента по индексам.
    // Это "неконстантная" версия:
    T& operator() (size_t i, size_t j) {
        return data[i][j];
    }

    // Это - "константная" версия. Если возможно, будет всегда вызываться она.
    const T& operator() (size_t i, size_t j) const {
        return data[i][j];
    }

    // Левая часть этого оператора - это текущий объект (*this)
    // Правая часть - это параметр other.
    // Традиционный += возвращает ссылку на сам изменённый объект.
    Matrix& operator += (const Matrix& other) {
        for (size_t i = 0; i != N; ++i)
            for (size_t j = 0; j != N; ++j)
                data[i][j] += other.data[i][j];
        // Можно было бы написать (*this)(i, j) += other(i, j);
        return *this;
    }

    // Обычный + возвращает новую матрицу, а исходную левую часть не изменяет.
    // Поэтому этот оператор константный.
    Matrix operator + (const Matrix& other) const {
        auto C = *this;
        C += other;  // реализуем + через +=
        return C;
    }

    MatrixIterator begin() const {
        return MatrixIterator<T, N> (0, 0);
    }

    MatrixIterator end() const {
        return MatrixIterator<T, N> (N, 0);
    }

    // Остальные операторы (-, -=, *, *=, ==, !=, унарный -) допишите сами.
};

template <typename  T, int N>
class MatrixIterator {
private:
    int i, j;
public:
    MatrixIterator(const int& i, const int& j) : i(i), j(j) {
    }

    MatrixIterator& operator ++ () {
        ++j;
        if (j == N) {
            j = 0;
            ++i;
        }

        return *this;
    }

    MatrixIterator operator ++ (int) {
        MatrixIterator<T, N> temp(*this);
        ++temp.j;
        if (temp.j == N) {
            temp.j = 0;
            ++temp.i;
        }

        return temp;
    }

    MatrixIterator& operator -- () {
        --j;
        if (j == -1) {
            j = N - 1;
            --i;
        }

        return *this;
    }

    MatrixIterator operator -- (int) {
        MatrixIterator<T, N> temp(*this);
        --temp.j;
        if (temp.j == -1) {
            temp.j = N - 1;
            --temp.i;
        }

        return temp;
    }

    bool operator == (const MatrixIterator<T, N>& other) const {
        return (i == other.i && j == other.j);
    }

    bool operator != (const MatrixIterator<T, N>& other) const {
        return !(*this == other);
    }
};*/


/*// Оператор сложения можно было бы сделать и "внешним" по отношению к классу.
// Только тогда доступа к приватному полю data у нас уже бы не было.
template <typename T, int N>
Matrix<T, N> operator + (
        const Matrix<T, N>& A,
        const Matrix<T, N>& B
) {
    Matrix<T, N> C;
    for (size_t i = 0; i != N; ++i)
        for (size_t j = 0; j != N; ++j)
            C(i, j) = A(i, j) + B(i, j);
    return C;
}

template <typename T, int N>
void print(const Matrix<T, N>& m) {
    for (size_t i = 0; i != N; ++i) {
        for (size_t j = 0; j != N; ++j)
            std::cout << m(i, j) << "\t";  // какая версия operator() здесь вызовется?
        std::cout << "\n";
    }
}*/

/*int main() {
    const int N = 3;
    Matrix<int, N> A(7);

    Matrix<int, N> B(-1);
    B(1, 2) = 5;
    B(2, 0) = -4;

    for (int x: M) {
        cout << x << ' ';
    }

    for (MatrixIterator it = 0; it < A.end(); ++it) {
        int x = *it;
        cout << x << ' ';
    }*/

/*print(A);
std::cout << "==========\n";
print(B);
std::cout << "==========\n";
print(A + B);
}*/
#include <iostream>
#include <vector>

using std::vector;

template <typename T, int N>
class Matrix;

template <typename  T, int N>
class RowIterator {
private:
    Matrix<T, N>& matrix;
    size_t row, column;
public:
    RowIterator(Matrix<T, N>& _matrix, size_t _row, size_t _column)
            : matrix(_matrix),
              row(_row),
              column(_column)
    {}

    T& operator * () {
        return matrix(row, column);
    }

    const T& operator * () const {
        return matrix(row, column);
    }

    RowIterator& operator ++ () {
        ++column;

        if (column == N) {
            column = 0;
            ++row;
        }

        return *this;
    }

    RowIterator operator ++ (int) {
        RowIterator temp(*this);
        ++temp.column;

        if (temp.column == N) {
            temp.column = 0;
            ++temp.row;
        }

        return temp;
    }

    bool operator == (const RowIterator& other) const {
        return (row == other.row && column == other.column);
    }

    bool operator != (const RowIterator& other) const {
        return !(*this == other);
    }
};

template <typename T, int N>
class Matrix {
private:
    vector<vector<T>> data;
    // тут могут быть и другие реализации: например, фиксированный массив T[N][N], или одномерный массив размера N^2

public:
    Matrix(const vector<vector<T>>& d)
            : data(d) {
    }

    // Конструктор для скалярной матрицы
    Matrix(const T& value = 0) {
        data.resize(N);
        for (auto& row : data)
            row.resize(N);
        for (size_t i = 0; i != N; ++i)
            data[i][i] = value;
    }

    // Перегрузим оператор "круглые скобки" для получения элемента по индексам.
    // Это "неконстантная" версия:
    T& operator() (size_t i, size_t j) {
        return data[i][j];
    }

    // Это - "константная" версия. Если возможно, будет всегда вызываться она.
    const T& operator() (size_t i, size_t j) const {
        return data[i][j];
    }

    // Левая часть этого оператора - это текущий объект (*this)
    // Правая часть - это параметр other.
    // Традиционный += возвращает ссылку на сам изменённый объект.
    Matrix& operator += (const Matrix& other) {
        for (size_t i = 0; i != N; ++i)
            for (size_t j = 0; j != N; ++j)
                data[i][j] += other.data[i][j];
        // Можно было бы написать (*this)(i, j) += other(i, j);
        return *this;
    }

    // Обычный + возвращает новую матрицу, а исходную левую часть не изменяет.
    // Поэтому этот оператор константный.
    Matrix operator + (const Matrix& other) const {
        auto C = *this;
        C += other;  // реализуем + через +=
        return C;
    }

    RowIterator<T, N> begin() {
        return RowIterator<T, N> (*this, 0, 0);
    }

    RowIterator<T,N> end() {
        return RowIterator<T, N> (*this, N, 0);
    }

    // Остальные операторы (-, -=, *, *=, ==, !=, унарный -) допишите сами.
};



/*// Оператор сложения можно было бы сделать и "внешним" по отношению к классу.
// Только тогда доступа к приватному полю data у нас уже бы не было.
template <typename T, int N>
Matrix<T, N> operator + (
        const Matrix<T, N>& A,
        const Matrix<T, N>& B
) {
    Matrix<T, N> C;
    for (size_t i = 0; i != N; ++i)
        for (size_t j = 0; j != N; ++j)
            C(i, j) = A(i, j) + B(i, j);
    return C;
}*/

template <typename T, int N>
void print(const Matrix<T, N>& m) {
    for (size_t i = 0; i != N; ++i) {
        for (size_t j = 0; j != N; ++j)
            std::cout << m(i, j) << "\t";  // какая версия operator() здесь вызовется?
        std::cout << "\n";
    }
}

int main() {
    const int N = 3;
    Matrix<int, N> A(7);

    Matrix<int, N> B(-1);
    B(1, 2) = 5;
    B(2, 0) = -4;

    for (int x: B) {
        std::cout << x << ' ';
    }

    print(A);
    std::cout << "==========\n";
    print(B);
    std::cout << "==========\n";
    print(A + B);
}



#include <iostream>
#include <vector>

using namespace std;

class MyIterator {
private:
    typename OuterCollection::const_iterator current_container;

public:
    MyIterator begin() {

    }
    MyIterator operator++() {

    }


};

template <typename OuterCollection>
MyIterator MakeRange(const OuterCollection&);

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    const vector<vector<int>> data = {
            {1, 2, 3},
            {},
            {4, 5, 6}};
    for (const auto x : MakeRange(data)) {
        cout << x << ", ";
    }

    for (MyIterator it = MakeRang(data);
}