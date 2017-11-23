class Solution {
public:
    string decodeString(string s) {
        string tmp = "";
        int cnt = 0;
        stack<pair<string, bool>> st;
        for (char ch : s) {
            if ('0' <= ch && ch <= '9') {
                if (tmp != "") {
                    st.push({tmp, true});
                    tmp = "";
                }
                
                cnt = cnt * 10 + (ch - '0');
            } else if (ch == '[') {
                st.push({to_string(cnt), false});
                cnt = 0;
            } else if (ch == ']') {
                while (!st.empty() && st.top().second) {
                    tmp = st.top().first + tmp;
                    st.pop();
                }
                string ss = "";
                for (int i = 0; i < stoi(st.top().first); i++) {
                    ss += tmp;
                }
                st.pop();
                tmp = "";
                st.push({ss, true});
            } else {
                tmp += ch;
            }
        }
        
        string ans = tmp;
        while (!st.empty()) {
            ans = st.top().first + ans;
            st.pop();
        }
        return ans;
    }
};
