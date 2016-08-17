class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> v, u;
        for (int i : nums1) {
            if (v.find(i) == v.end()) v[i] = 0;
            v[i] = v[i] + 1;
        }
        for (int i : nums2) {
            if (u.find(i) == u.end()) u[i] = 0;
            u[i] = u[i] + 1;
        }
        vector<int> r;
        for (auto& k : u) {
            if (v.find(k.first) != v.end()) {
                for (int i = 0; i < min(k.second, v[k.first]); i++) {
                    r.push_back(k.first);
                }
            }
        }
        return r;
    }
};