class Solution {
public:
    string frequencySort(string s) {
        vector<int> vi(256, 0);
        for (char ch : s) vi[(int)ch]++;
        vector<pair<int, char>> vp;
        for (int i = 0; i < vi.size(); i++) {
            if (vi[i] > 0) {
                vp.push_back({vi[i], (char) i});
            }
        }
        sort(vp.rbegin(), vp.rend());
        string t = "";
        for (auto p : vp) {
            t += string(p.first, (char) p.second);
        }
        return t;
    }
};
