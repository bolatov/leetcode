class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, (j - i) * min(height[i], height[j]));
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            ans = max(ans, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};
