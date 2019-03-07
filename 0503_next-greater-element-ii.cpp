class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) return {};
        
        vector<int> vi(nums.size(), -1);
        stack<pair<int, int>> st;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[idx] < nums[i]) {
                idx = i;
            }
            while (!st.empty() && st.top().first < nums[i]) {
                vi[st.top().second] = nums[i];
                st.pop();
            }
            st.push({nums[i], i});
        }
        for (int i = 0; i <= idx; i++) {
            while (!st.empty() && st.top().first < nums[i]) {
                vi[st.top().second] = nums[i];
                st.pop();
            }
            st.push({nums[i], i});
        }
        return vi;
    }
};
