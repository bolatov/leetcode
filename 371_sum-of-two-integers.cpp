class Solution {
public:
    int getSum(int a, int b) {
        int q = 0, x, y, z;
        int r = 0;
        int MAX_BITS = sizeof(int) * CHAR_BIT; // 32-bit integer, for example
        
        // categories of summands:
        // 0 - both are positive
        // 1 - both are negative
        // 2 - one of them is positive, another one is negative
        const int category = (a >= 0 && b >= 0 ? 0 : (a < 0 && b < 0 ? 1 : 2));
        if (category == 1) {
            a = abs(a);
            b = abs(b);
        }
        for (int i = 0; i < MAX_BITS; i++) {
            x = (a & (1 << i)) > 0;
            y = (b & (1 << i)) > 0;
            
            z = (!q && (x ^ y)) || (q && !(x ^ y));
            if (x == y && y == q) {
                q = x;
            } else { 
                q = !z;
            }
            r |= z << i;
        }
        
        // convert the result according to the category of summands
        return (category == 0) ? r : (category == 1 ? -r : INT_MAX + r + 1);
    }
};
