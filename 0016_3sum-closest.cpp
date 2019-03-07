class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        int l, r, n = nums.size();
        for (int i = 0; i < n; i++) {
            l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                }
                
                if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
};
