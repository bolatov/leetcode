class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {       
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        
        for (int i = 1; i < nums.size(); i++) {
            if ((k == 0 && nums[i] == 0) ||
                (k != 0 && nums[i] % k == 0)) {
                return true;
            }
            
            for (int j = 0; j + 1 < i; j++) {
                int sum = nums[i] - nums[j];
                if ((k == 0 && sum == 0) ||
                    (k != 0 && sum % k == 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
