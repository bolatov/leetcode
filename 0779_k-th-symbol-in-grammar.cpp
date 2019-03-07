class Solution {
private:
    /**
     * Follows the path to the target leaf.
     */
    int helper(int val, int N, int K) {
        if (N == 1) {
            return val;
        }
        
        // Half of the number of leaves on the target row.
        int m = 1 << (N-2);
        
        // Decide to take right child,
        if (K > m) {
            val = (val == 0) ? 1 : 0;
            return helper(val, N-1, K-m);
        } 
        
        // or left child.
        else {
            val = (val == 1) ? 1 : 0;
            return helper(val, N-1, K);
        }
    }
public:
    int kthGrammar(int N, int K) {
        return helper(0, N, K);
    }
};
