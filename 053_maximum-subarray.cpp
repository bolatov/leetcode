class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Solve by Kadane's algorithm
        // source: https://en.wikipedia.org/wiki/Maximum_subarray_problem
        
        // max ending here
        int cur = nums.empty() ? 0 : nums[0];
        
        // max so far
        int ans = cur;
        for (int i = 1; i < nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            ans = max(ans, cur);
        }
        return ans;
    }
};
