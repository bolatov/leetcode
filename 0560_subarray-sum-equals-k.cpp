class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
               
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (k == nums[i]);
            for (int j = 0; j < i; j++) {
                if (nums[i] - nums[j] == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
