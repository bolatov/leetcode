class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        vector<bool> u(nums.size(), false);
        for (int i : nums) {
            if (!u[i]) {
                int cnt = 1;
                for (int ai = nums[i]; ai != i; ai = nums[ai]) {
                    u[ai] = true;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
