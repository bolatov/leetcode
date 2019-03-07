class Solution {
private:
    bool helper(vector<int>& nums, vector<long>& buckets, long target, int idx) {
        if (idx < 0) {
            for (int i : buckets) {
                if (i != target) {
                    return false;
                }
            }
            return true;
        }
        
        int num = nums[idx];
        for (int i = 0; i < buckets.size(); i++) {
            if (buckets[i] + num <= target) {
                buckets[i] += num;
                if (helper(nums, buckets, target, idx - 1)) {
                    return true;
                }
                buckets[i] -= num;
            }
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum < k || sum % k != 0) {
            return false;
        }
        long target = sum / k;
        sort(nums.begin(), nums.end());
        vector<long> buckets(k, 0);
        return helper(nums, buckets, target, nums.size() - 1);
    }
};
