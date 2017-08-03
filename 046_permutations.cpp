class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return {{}};
        }
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> vvi = {nums};
        int n = nums.size();
        int i = n - 1;
        int j;
        while (true) {
            for (i = n - 1; i > 0; i--) {
                if (nums[i - 1] < nums[i]) {
                    break;
                }
            }
            
            if (i == 0) {
                break;
            }
            
            for (j = n - 1; j > i - 1; j--) {
                if (nums[j] > nums[i - 1]) {
                    break;
                }
            }
            swap(nums[i - 1], nums[j]);
            reverse(nums.begin() + i, nums.end());
            vvi.push_back(nums);
        }
        return vvi;
    }
};
