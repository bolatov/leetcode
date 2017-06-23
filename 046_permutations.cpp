class Solution {
private:
    vector<vector<int>> f(vector<int> nums) {
        vector<vector<int>> vvi;
        if (nums.size() < 2) {
            vvi.push_back(nums);
            return vvi;
        }
        
        if (nums.size() == 2) {
            vvi.push_back({nums[0], nums[1]});
            vvi.push_back({nums[1], nums[0]});
            return vvi;
        } 
        
        for (int i = 0; i < nums.size(); i++) {
            vector<int> vi(nums.begin(), nums.begin() + i);
            vi.insert(vi.end(), nums.begin() + i + 1, nums.end());
            
            auto tmp = f(vi);
            for (auto v : tmp) {
                vector<int> vt = {nums[i]};
                vt.insert(vt.end(), v.begin(), v.end());
                vvi.push_back(vt);
            }
        }
        
        return vvi;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return {{}};
        }
        return f(nums);
    }
};
