class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for (string w : words) {
            if (!mp.count(w)) mp[w] = 0;
            mp[w]++;
        }
        map<int, vector<string>> miv;
        for (auto kv : mp) {
            if (!miv.count(kv.second)) {
                vector<string> tmp;
                miv[kv.second] = tmp;
            }
            miv[kv.second].push_back(kv.first);
        }
        vector<string> vs;
        for (auto it = miv.rbegin(); it != miv.rend() && vs.size() <= k; it++) {
            auto v = it->second;
            vs.insert(vs.end(), v.begin(), v.begin() + min(v.size(), k - vs.size()));
        }
        
        return vs;
    }
};
