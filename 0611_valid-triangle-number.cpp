class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j + 1 < nums.size(); j++) {
                int a = nums[i];
                int b = nums[j];
                
                int minValue = b - a + 1;
                int maxValue = a + b - 1;
                
                auto start = nums.begin() + j + 1;
                auto low = lower_bound(start, nums.end(), minValue);
                auto up = upper_bound(start, nums.end(), maxValue);
                int diff = up - low;
                
                ans += max(0, diff);
            }
        }
        
        return ans;
    }
};
