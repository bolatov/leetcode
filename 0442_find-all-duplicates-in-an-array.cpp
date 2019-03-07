class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        //  0 - empty cell
        // -1 - duplicate
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] != i + 1) {
                int j = nums[i] - 1;
                if (nums[i] == nums[j]) {
                    nums[i] = 0;
                    nums[j] = -1;
                } else {
                    swap(nums[i], nums[j]);
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                v.push_back(i + 1);
            }
        }
        return v;
    }
};
