class Solution {
private:
    int dfs(vector<int>& nums, int i, int sum) {
        if (i >= nums.size()) {
            return sum == 0;
        }
        
        return dfs(nums, i + 1, sum - nums[i]) + 
            dfs(nums, i + 1, sum + nums[i]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums, 0, S);
    }
};
