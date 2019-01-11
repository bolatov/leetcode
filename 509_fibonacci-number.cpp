class Solution {
public:
    int fib(int N) {
        int prev = 0, cur = 1;
        if (N == 0) return prev;
        else if (N == 1) return cur;
        int tmp;
        for (int i = 2; i <= N; i++) {
            tmp = prev + cur;
            prev = cur;
            cur = tmp;
        }
        return cur;
    }
};
