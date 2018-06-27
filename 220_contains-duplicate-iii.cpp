class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0 || nums.size() <= 1) return false;
        vector<long> vi(min(k + 1, (int) nums.size()));
        for (int i = 0; i < vi.size(); i++) {
            vi[i] = nums[i];
        }
        sort(vi.begin(), vi.end());
        
        for (int i = 1; i < vi.size(); i++) {
            if (vi[i] - vi[i - 1] <= t) return true;
        }
        
        for (int i = vi.size(); i < nums.size(); i++) {
            auto it = find(vi.begin(), vi.end(), nums[i - vi.size()]);
            vi.erase(it);
            
            int pos = 0;
            for (pos = 0; pos < vi.size(); pos++) {
                if (nums[i] <= vi[pos]) break;
            }
            vi.insert(vi.begin() + pos, nums[i]);
            if ((pos + 1 <= k && vi[pos + 1] - vi[pos] <= t) || 
                (pos - 1 >= 0 && vi[pos] - vi[pos - 1] <= t)) return true;
        }
        return false;
    }
};
