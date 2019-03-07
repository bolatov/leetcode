class Solution {
public:
    int findLHS(vector<int>& nums) {
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        unordered_map<int, int> mp;
        for (int i : nums) {
            minValue = min(minValue, i);
            maxValue = max(maxValue, i);
            if (!mp.count(i)) mp[i] = 0;
            mp[i]++;
        }
        int ans = 0;
        for (auto kv : mp) {
            int i = kv.first;
            if (mp.count(i - 1)) ans = max(ans, mp[i] + mp[i - 1]);
            if (mp.count(i + 1)) ans = max(ans, mp[i] + mp[i + 1]);
        }
        return ans;
    }
};
