class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx = 0;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (mx < nums[i]) {
                mx = nums[i];
                idx = i;
            }
        }

        for (int i : nums) if (i != mx && i * 2 > mx) return -1;
        return idx;
    }
};
