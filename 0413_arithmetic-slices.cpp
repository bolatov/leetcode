class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        
        int ans = 0;
        int be = 0;
        int diff = A[1] - A[0];
        for (int en = 1; en < A.size(); en++) {
            if (A[en] - A[en - 1] != diff) {
                int len = (en - 1) - be + 1;
                int n = len - 2;
                ans += n * (n + 1) / 2;
                be = en - 1;
                diff = A[en] - A[en - 1];
            } else if (en + 1 == A.size() && A[en] - A[en - 1] == diff) {
                int len = en - be + 1;
                int n = len - 2;
                ans += n * (n + 1) / 2;
            }
        }
        return ans;
    }
};
