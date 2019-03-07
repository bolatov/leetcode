class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Hint 1  
        // For each j, let opt(j) be the smallest i so that nums[i] * nums[i+1] * ... * nums[j] is less than k. 
        // opt is an increasing function.
        int n = nums.size();
        int cnt = 0;
        int be = 0, en = 0, p = 1;
        while (en < n) {
            if (nums[en] >= k) {
                p = 1;
                en++;
                be = en;
                continue;
            }
            
            p *= nums[en];
            while (p >= k && be <= en) {
                p /= nums[be++];
            }
            
            cnt += en - be + 1;
            en++;
        }
        
        return cnt;
    }
};
