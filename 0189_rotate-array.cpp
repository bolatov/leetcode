class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        // version 1
        // int n = nums.size();
        // vector<int> vi(n);
        // for (int i = 0; i < n; i++) {
        //     vi[(i + k) % n] = nums[i];
        // }
        // nums = vi;

        // version 2
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
