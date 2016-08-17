class Solution {
public:
    bool isUgly(int n) {
        if (n < 1) return 0;
        if (n == 1) return 1;
        
        for (int i : {2, 3, 5})
            while (n % i == 0) n /= i;
        
        return n == 1;
    }
};
