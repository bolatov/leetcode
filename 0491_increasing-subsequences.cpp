class Solution {
private:
    vector<vector<int>> vvi;
    unordered_set<string> visited;
    void dfs(vector<int>& nums, vector<int>& vi, string key, int i) {
        if (vi.size() >= 2) {
            if (!visited.count(key)) {   
                vvi.push_back(vi);
                visited.insert(key);
            }
        }
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[i]) continue;
            vector<int> vj(vi);
            vj.push_back(nums[j]);
            dfs(nums, vj, key + "#" + to_string(nums[j]), j);
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.empty()) return vvi;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> vi = {nums[i]};
            dfs(nums, vi, to_string(nums[i]), i);
        }
        return vvi;
    }
};
