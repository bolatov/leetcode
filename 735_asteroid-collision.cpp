class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i : asteroids) {
            int val = i;
            bool hasSurvived = true;
            while (val < 0 && !st.empty() && st.top() > 0) {
                int top = st.top();
                st.pop();
                if (abs(val) == abs(top)) {
                    hasSurvived = false;
                    break;
                } else {
                    val = abs(top) > abs(val) ? top : val;
                }
            }
            if (hasSurvived) {
                st.push(val);
            }
        }
        int sz = st.size();
        vector<int> vi(sz);
        while (!st.empty()) {
            vi[--sz] = st.top();
            st.pop();
        }
        return vi;
    }
};
