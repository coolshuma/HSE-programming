#include <algorithm>
#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int n, m;
    cin >> n >> m;
    int size = 0;
    int count_of_kingdoms = 0;
    for (count_of_kingdoms = 1; count_of_kingdoms; ++count_of_kingdoms) {
        size += count_of_kingdoms;
        if (size > n * m) {
            count_of_kingdoms--;
            break;
        }
    }

    cout << count_of_kingdoms;

    vector<vector<char>> field(n, vector<char>(m));

    char l1 = 'A';
    char l2 = 'B';
    char l3 = 'C';
    char i1 = 'D';
    char i2 = 'E';
    char i3 = 'F';
    int row = 0;

    for (int t = 1; t <= count_of_kingdoms; ++t) {
        int last_t = t;
        int pos = 0;
        if (m - pos < last_t) {
            for (; pos < m; ++pos) {
                field[row][pos] = l3;
            }
            ++row;
            pos = 0;
        }
    }

    return 0;
}

