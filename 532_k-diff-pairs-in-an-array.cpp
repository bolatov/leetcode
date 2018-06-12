class Solution {
public:
    int findPairs(vector<int>& numz, int k) {
        if (k < 0) {
            return 0;
        }
        map<int, int> mp;
        for (int i : numz) {
            if (!mp.count(i)) mp[i] = 0;
            mp[i]++;
        }
        
        vector<int> unique;
        int ans = 0;
        int duplicates = 0;
        for (auto kv : mp) {
            unique.push_back(kv.first);
            if (kv.second > 1) duplicates++;
        }
        
        if (k == 0) {
            return duplicates;
        }
        
        for (int i = 0; i + 1 < unique.size(); i++) {
            int lo = i + 1, hi = unique.size() - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int diff = unique[mid] - unique[i];
                if (diff == k) {
                    ans++;
                    break;
                } else if (diff > k) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        return ans;
    }
};
