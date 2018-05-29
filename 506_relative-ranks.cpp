class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int sz = nums.size();
        map<int, int> mp;
        for (int i = 0; i < sz; i++) {
            mp[nums[i]] = i;
        }
        
        vector<string> vs(sz);
        vector<string> vm = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        int i = 0;
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            // printf("%d -> %d\n", it->first, it->second);
            if (0 <= i && i < 3) vs[it->second] = vm[i];
            else vs[it->second] = to_string(i + 1);
            i++;
        }
        return vs;
    }
};
