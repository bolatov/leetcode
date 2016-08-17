class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                for (int j = i + 1; j < nums.size() && nums[j] != 0; j++) {
                    int t = nums[j];
                    nums[j] = nums[j - 1];
                    nums[j - 1] = t;
                }
            }
        }
    }
};