#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        if ((1 << i) & n)
            cnt++;
    }
    return cnt;
}

int main() {
    printf("%d = %d\n", hammingWeight(1), 1);
    printf("%d = %d\n", hammingWeight(2), 1);
    printf("%d = %d\n", hammingWeight(3), 2);
    printf("%d = %d\n", hammingWeight(4), 1);
    printf("%d = %d\n", hammingWeight(5), 2);
    printf("%d = %d\n", hammingWeight(6), 2);
    printf("%d = %d\n", hammingWeight(7), 3);
    printf("%d = %d\n", hammingWeight(8), 1);
    printf("%d = %d\n", hammingWeight(9), 2);
    return 0;
}