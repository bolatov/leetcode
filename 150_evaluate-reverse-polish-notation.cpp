class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int t, n;
        for (string s : tokens) {
            if ("+" == s) {
                n = st.top();
                st.pop();
                t = st.top();
                st.pop();
                st.push({t + n});
            } else if ("-" == s) {
                n = st.top();
                st.pop();
                t = st.top();
                st.pop();
                st.push({t - n});
            } else if ("*" == s) {
                n = st.top();
                st.pop();
                t = st.top();
                st.pop();
                st.push({t * n});
            } else if ("/" == s) {
                n = st.top();
                st.pop();
                t = st.top();
                st.pop();
                st.push({t / n});
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
