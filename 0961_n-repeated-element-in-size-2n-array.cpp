class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        if (A[n / 2 - 1] == A[n / 2] ||
           A[n / 2] == A[n - 1]) return A[n / 2];
        return A[0];
    }
};
