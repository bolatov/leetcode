class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<pair<int, char>> st;
        for (int i = 0; i < S.size(); i++) {           
            if (S[i] == '(') {
                if (i + 1 < S.size() && S[i + 1] == ')') {
                    st.push({1, '+'});
                    i++;
                } else {
                    st.push({2, '*'});
                }
            } else {
                while (!st.empty()) {
                    auto p = st.top();
                    st.pop();
                    auto n = st.top();
                    st.pop();
                    if (n.second == '*') {
                        st.push({p.first * n.first, '+'});
                        break;
                    } else {
                        st.push({p.first + n.first, '+'});
                    }
                }
            }
        }
        
        while (st.size() > 1) {
            auto top = st.top();
            st.pop();
            auto nxt = st.top();
            st.pop();
            int val = (nxt.second == '+') ? top.first + nxt.first : top.first * nxt.first;
            st.push({val, '-'});
        }
        return st.top().first;
    }
};
