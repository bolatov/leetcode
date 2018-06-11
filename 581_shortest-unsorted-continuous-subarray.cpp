class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> vi(nums);
        sort(vi.begin(), vi.end());
        int mn = nums.size(), mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (vi[i] != nums[i]) {
                mx = max(i, mx);
                mn = min(i, mn);
            }
        }
        return max(0, mx - mn + 1);
    }
};
