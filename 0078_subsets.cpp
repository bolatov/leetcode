class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vvi;
        vvi.push_back(vector<int> ());
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> temp;
            for (int j = 0; j < vvi.size(); j++) {
                vector<int> v(vvi[j]);
                v.push_back(nums[i]);
                temp.push_back(v);
            }
            vvi.insert(vvi.end(), temp.begin(), temp.end());
        }
        return vvi;
    }
};
