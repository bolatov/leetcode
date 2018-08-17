class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<long long> vll(n, nums[0]);
        for (int i = 1; i < n; i++) {
            vll[i] = vll[i - 1] + nums[i];
        }
        if (vll[n - 1] < s) return 0;
        
        int ans = n;
        for (int i = 0; i < n; i++) {
            if (vll[i] < s) continue;
            
            ans = min(ans, i + 1);
            int lo = 0, hi = i - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                long long sum = vll[i] - vll[mid];
                if (sum == s) {
                    ans = min(ans, i - mid);
                    break;
                } else if (sum > s) {
                    lo = mid + 1;
                    ans = min(ans, i - mid);
                } else {
                    hi = mid - 1;
                }
            }
        }
        return ans;
    }
};
