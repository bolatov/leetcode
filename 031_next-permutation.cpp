class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        int ind = pos + 1;
        for (int i = pos + 1; i < nums.size(); i++) {
            if (nums[i] < nums[ind] && nums[i] > nums[pos]) {
                ind = i;
            }
        }
        swap(nums[pos], nums[ind]);
        sort(nums.begin() + pos + 1, nums.end());
    }
};
