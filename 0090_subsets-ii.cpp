class Solution {
private:
    string toStr(vector<int>& vi) {
        if (vi.empty()) return "";
        string s = to_string(vi[0]);
        for (int i = 1; i < vi.size(); i++) {
            s += "#" + to_string(vi[i]);
        }
        return s;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> vvi = {{}};
        unordered_set<string> visited;
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> temp;
            for (int j = 0; j < vvi.size(); j++) {
                vector<int> v(vvi[j]);
                v.push_back(nums[i]);
                
                string k = toStr(v);
                if (visited.count(k) == 0) {
                    visited.insert(k);
                    temp.push_back(v);
                }
            }
            vvi.insert(vvi.end(), temp.begin(), temp.end());
        }
        return vvi;
    }
};
