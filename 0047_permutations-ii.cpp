class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> vvi = {nums};
        int n = nums.size();
        
        while (true) {
            int idx = -1;
            for (int i = n - 1; i > 0; i--) {
                if (nums[i - 1] < nums[i]) {
                    idx = i - 1;
                    break;
                }
            }
            
            if (idx < 0) {
                break;
            }
            
            int iNext = idx + 1;
            for (int i = iNext; i < n; i++) {
                if (nums[i] > nums[idx] && nums[i] < nums[iNext]) {
                    iNext = i;
                }
            }
            
            swap(nums[idx], nums[iNext]);
            sort(nums.begin() + idx + 1, nums.end());
            vvi.push_back(nums);
        }
        
        return vvi;
    }
};
