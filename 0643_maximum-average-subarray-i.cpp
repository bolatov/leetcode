class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {    
        double sum = 0.0;
        for (int i = 0; i < k; i++) {
            sum += (double) nums[i];
        }
        double maxSum = sum;
        for (int i = k; i < nums.size(); i++) {
            sum -= nums[i - k];
            sum += nums[i];
            maxSum = max(sum, maxSum);
        }
        return maxSum / (double) k;
    }
};
