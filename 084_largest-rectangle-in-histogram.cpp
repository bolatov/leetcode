// http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        int i = 0;
        while (i < heights.size()) {
            if (st.empty() || heights[st.top()] <= heights[i]) {
                st.push(i++);
            } else {
                int top = st.top();
                st.pop();
                int area = heights[top] * (st.empty() ? i : i - st.top() - 1);
                ans = max(area, ans);
            }
        }
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            int area = heights[top] * (st.empty() ? i : i - st.top() - 1);
            ans = max(area, ans);
        }
        
        return ans;
    }
};
