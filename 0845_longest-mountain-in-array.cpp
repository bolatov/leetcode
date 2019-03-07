class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ans = 0;
        int be = 0;
        int n = A.size();
        while (be < n) {
            int mid = be + 1;
            for (int k = mid; A[k - 1] < A[k] && k < n; k++) mid = k;

            if (A[be] >= A[mid]) {
                be = mid;
                continue;
            }
            
            int en = mid + 1;
            while (en < n && A[en - 1] > A[en]) {
                ans = max(ans, en - be + 1);
                en++;
            }
            be = en - 1;
        }
        return ans;
    }
};
