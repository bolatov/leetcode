#include <iostream>
#include <fstream>

using namespace std;

int trailingZeroes(int n) {
    int t = 0, f = 0, x = 0;
    for (int i = 2; i <= n; i += 10) {
        t++;
    }
    for (int i = 5; i <= n; i += 10) {
        f++;
    }
    for (int i = 10; i <= n; i += 10) {
        x++;
    }
    return min(t, f) + x;
}

int main() {
    cout << "n=100,               24 ?=? " << trailingZeroes(100) << endl;
    cout << "n=1000,             249 ?=? " << trailingZeroes(1000) << endl;
    cout << "n=10000,           2499 ?=? " << trailingZeroes(10000) << endl;
    cout << "n=100000,         24999 ?=? " << trailingZeroes(100000) << endl;
    cout << "n=1000000,       249998 ?=? " << trailingZeroes(1000000) << endl;
    cout << "n=10000000,     2499999 ?=? " << trailingZeroes(10000000) << endl;
    cout << "n=1808548329, 452137076 ?=? " << trailingZeroes(1808548329)
         << endl;
    // cout << "n=1000000000, 249998 ?=? " << trailingZeroes(1000000000) <<
    // endl;
    return 0;
}