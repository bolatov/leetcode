class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int cur = nums.empty() ? 0 : nums[0];
        int rev = nums.empty() ? 0 : nums[n - 1];
        int ans = cur;
        for (int i = 1; i < nums.size(); i++) {
            ans = max(nums[i], ans);
            cur = (cur == 0) ? nums[i] : cur * nums[i];
            rev = (rev == 0) ? nums[n - i - 1] : rev * nums[n - i - 1];
            ans = max(cur, ans);
            ans = max(rev, ans);
        }
        return ans;
    }
};
