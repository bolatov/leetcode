class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        size_t maxLen = 0;
        vector<int> keys;
        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i];
            if (mp.find(key) == mp.end()) {
                vector<int> em = {};
                mp[key] = em;
            }
            mp[key].push_back(i);
            size_t sz = mp[key].size();
            if (sz > maxLen) {
                keys.clear();
                maxLen = sz;
                keys.push_back(key);
            } else if (sz == maxLen) {
                keys.push_back(key);
            }
        }
        int minLen = nums.size();
        for (int key : keys) {
            int len = mp[key][maxLen - 1] - mp[key][0] + 1;
            minLen = min(minLen, len);
        }
        return minLen;
    }
};
