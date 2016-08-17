class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zeros = 0;
        for (int i : nums) {
            if (i)           product *= i;
            else if (i == 0) zeros++;
        }
        vector<int> v(nums.size(), 0);
        if  (zeros < 2) {
            for (int i = 0; i < nums.size(); i++) {
                if (zeros == 0) {
                    v[i] = product / nums[i];
                } else if (nums[i] == 0) {
                    v[i] = product;
                } else {
                    v[i] = 0;
                }
            }
        }
        return v;
    }
};
