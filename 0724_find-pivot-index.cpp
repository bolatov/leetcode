class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        else if (n == 1) return 0;
        
        vector<int> vl(n, nums[0]), vr(n, nums[n - 1]);
        for (int i = 1; i < n; i++)      vl[i] = vl[i - 1] + nums[i];
        for (int i = n - 2; i >= 0; i--) vr[i] = vr[i + 1] + nums[i];
        
        for (int i = 0; i < n; i++) {
            int l = (i - 1 < 0)  ? 0 : vl[i - 1];
            int r = (i + 1 >= n) ? 0 : vr[i + 1];
            if (l == r) return i;
        }
        
        return -1;
    }
};
