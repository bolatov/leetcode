class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        for (; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                break;
            }
        }
        
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int j;
        for (j = nums.size() - 1; j > i - 1; j--) {
            if (nums[j] > nums[i - 1]) {
                break;
            }
        }
        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());
    }
};
