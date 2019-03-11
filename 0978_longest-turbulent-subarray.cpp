class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        if (n <= 1) return n;
        if (n == 2) {
            return A[0] != A[1] ? 2 : 1;
        }
        int ans = A[1] != A[0] ? 2 : 1;
        int cur = ans;
        for (int i = 1; i + 1 < n; i++) {
            if ((A[i - 1] < A[i] && A[i] > A[i + 1]) ||
                (A[i - 1] > A[i] && A[i] < A[i + 1])) {
                cur++;
            } else if (A[i - 1] == A[i + 1]){
                cur = 1;
            } else {
                cur = 2;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
