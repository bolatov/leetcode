class NumArray {
  private:
    vector<int> nums;

  public:
    NumArray(vector<int> &nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        this->nums = nums;
    }

    int sumRange(int i, int j) {
        return i > 0 ? nums[j] - nums[i - 1] : nums[j];
    }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);