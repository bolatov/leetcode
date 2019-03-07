// Explore "Stacks & Queues"
class Solution {
private:
    bool isBetween(char ch, char start, char end) {
        return start <= ch && ch <= end;
    }
    void p(stack<string> st) {
        cout << "Stack: ";
        while(!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
public:
    string decodeString(string s) {
        if (s.empty()) return "";
        s = "1[" + s + "]";
        stack<string> st;
        for (char ch : s) {
            if (ch == '[') {
                st.push("[");
            } else if (ch == ']') {
                string top = st.top();
                st.pop(); // pop letters
                st.pop(); // pop '['
                string num = st.top();
                int n = stoi(num);
                st.pop();
                string x = "";
                if (!st.empty() && (isBetween(st.top()[0], 'a', 'z') || isBetween(st.top()[0], 'A', 'Z'))) {
                    x = st.top();
                    st.pop();
                }
                while (n--) {
                    x += top;
                }
                st.push(x);
                // p(st);
            } else if ('0' <= ch && ch <= '9') {
                string num = "";
                if (!st.empty() && isBetween(st.top()[0], '0', '9')) {
                    num = st.top();
                    st.pop();
                }
                st.push(num + ch);
            } else {
                string w = "";
                if (!st.empty() && (isBetween(st.top()[0], 'a', 'z') || (isBetween(st.top()[0], 'A', 'Z')))) {
                    w = st.top();
                    st.pop();
                }
                st.push(w + ch);
            }
        }
        return st.top();
    }
};

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
