// https://en.wikipedia.org/wiki/3SUM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i > 2; i--) {
            if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2] && nums[i] == nums[i - 3]) {
                nums.erase(nums.begin() + i);
            }
        }
        vector<vector<int>> vvi;
        for (int i = 0; i + 2 < nums.size(); i++) {
            int a = nums[i];
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                int b = nums[start];
                int c = nums[end];
                if (a + b + c == 0) {
                    vvi.push_back({a, b, c});
                    start++;
                    end--;
                } else if (a + b + c > 0) {
                    end--;
                } else {
                    start++;
                }
            }
        }
        
        sort(vvi.begin(), vvi.end());
        for (int i = vvi.size() - 1; i > 0; i--) {
            if (vvi[i][0] == vvi[i - 1][0] && vvi[i][1] == vvi[i - 1][1]) {
                vvi.erase(vvi.begin() + i);
            }
        }
        
        return vvi;
    }
    
    // Solved again on Aug 17, 2018
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vvi;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            if (!vvi.empty() && vvi[vvi.size() - 1][0] == nums[i]) {
                continue;
            }
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    if (vvi.empty() || !(vvi[vvi.size() - 1][0] == nums[i] && vvi[vvi.size() - 1][1] == nums[l])) {
                        vvi.push_back({nums[i], nums[l], nums[r]});
                    }
                }
                
                if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return vvi;
    }
};
