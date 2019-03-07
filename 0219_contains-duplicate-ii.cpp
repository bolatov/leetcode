class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = vector<int>();
            }
            mp[nums[i]].push_back(i);
        }
        for (auto i = mp.begin(); i != mp.end(); i++) {
            for (int j = 1; j < i->second.size(); j++) {
                if (abs(i->second[j] - i->second[j-1]) <= k) return 1;
            }
        }
        return 0;
    }
};
