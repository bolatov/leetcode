class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) {
            return "";
        }
        
        if (path[0] == '/') {
            path = path.substr(1);
        }

        if (path[path.size() - 1] == '/') {
            path = path.substr(0, path.size() - 1);
        }
        
        //printf("trimmed: %s\n", path.c_str());

        size_t idx = 0;
        stack<string> st;
        for (size_t pos = path.find('/', idx); pos != string::npos; pos = path.find('/', idx)) {
            string s = path.substr(idx, (pos - idx));
            if (s.empty()) {
                idx = pos + 1;
                continue;
            }
            //printf("s==%s idx=%d pos=%d\n", s.c_str(), idx, pos);
            if (s == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (s != ".") {
                st.push(s);
            }
            idx = pos + 1;
        }
        
        string sub = path.substr(idx);
        if (sub == "..") {
            if (!st.empty()) {
                st.pop();
            }
        } else if (sub != ".") {
            st.push(sub);
        }
        
        string ans = st.empty() ? "/" : "";
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        if (ans.size() > 1 && ans[ans.size() - 1] == '/') {
            ans = ans.substr(0, ans.size() - 1);
        }

        return ans;
    }
};
