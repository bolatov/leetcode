class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen = 0;
        int be = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                maxLen = max(maxLen, i - be);
                be = i;
            }
        }
        return max(maxLen, n - be);
    }
};
