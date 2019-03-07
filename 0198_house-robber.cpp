class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int) nums.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        }
        for (int i = 2; i < n; i++) {
            if (i - 3 >= 0 && nums[i - 3] > nums[i - 2]) {
                nums[i] += nums[i - 3];
            } else {
                nums[i] += nums[i - 2];
            }
        }
        return max(nums[n - 1], nums[n - 2]);
    }
};
