class Solution {
private:
    int n;
    vector<int> arr;
    int hops(int j, int target) {
        int lo = j + 1, hi = n - 1;
        int idx = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == target) {
                idx = mid;
                break;
            } else if (arr[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return (idx > j) ? hops(idx, arr[j] + arr[idx]) + 1 : 0;
    }
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int ans = 0;
        n = A.size();
        arr = A;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int h = hops(j, arr[i] + arr[j]);
                if (h > 0) {
                    ans = max(ans, h + 2);
                }
            }
        }
        return ans;
    }
};
