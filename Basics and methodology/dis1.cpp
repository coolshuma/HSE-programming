#include <iostream>

int main() {
    long long sum = 0;
    for (long long i = 1; i < 1000000; ++i) {
        long long t = i;
        bool f = false;
        while(t) {
            if ((t % 10) == 1)
                f = true;
            t /= 10;
        }
        if (f) {
            sum++;
            std::cout << i << std::endl;
        }
    }
    std::cout << sum << std::endl; 
    long long sum2 = 0;
    long long dec = 1;
    for (int i = 0; i < 6; ++i) {
        int cur_sum = 0;
        for (int j = 1; j < 10; j += 2) {
            cur_sum += j * dec;
        }
        dec *= 10;
        std::cout << cur_sum << std::endl;
        sum2 += cur_sum * 5*5*5*5;
    }
    std::cout << sum2;
}
