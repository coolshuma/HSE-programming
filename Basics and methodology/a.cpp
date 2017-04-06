#include <iostream>
#include <string>
#include <vector>

bool can_make_palindrom(const std::string& line) {    
    std::vector<int> code(128);
    for (int i = 0; i < line.length(); ++i) {
        ++code[line[i]];
    }

    int count_of_odd = 0;
    for (int elem : code) {
        count_of_odd += elem % 2;
    }
    if (count_of_odd > 1)
        return 0;
    else
        return 1;
}

int main() {
    std::string line;
    getline(std::cin, line);
    can_make_palindrom(line);
}
