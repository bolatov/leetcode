class Solution {
public:
    bool check(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkPossibility(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                int p = nums[i - 1];
                nums[i - 1] = nums[i];
                if (check(nums)) return true;
                
                nums[i - 1] = p;
                nums[i] = p;
                return check(nums);
            }
        }
        return true;
    }
};
