class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int lo = 0, hi = A.size() - 1;
        while (lo < hi) {
            if (A[lo] % 2 == 0) {
                lo++;
                continue;
            }
            if (A[hi] % 2 == 1) {
                hi--;
                continue;
            }
            swap(A[lo], A[hi]);
            lo++;
            hi--;
        }
        return A;
    }
};
