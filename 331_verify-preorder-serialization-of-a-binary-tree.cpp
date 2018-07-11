class Solution {
private:
    void f(stack<string>& st) {
        if (st.size() < 3) return;
        string c = st.top();
        st.pop();
        
        string b = st.top();
        st.pop();
        
        string a = st.top();
        st.pop();
        
        if (b == c && c == "#" && a != "#") {
            st.push("#");
            f(st);
        } else {
            st.push(a);
            st.push(b);
            st.push(c);
        }
    }
    
    void printStack(stack<string> st) {
        printf("[");
        while (!st.empty()) {
            printf("'%s'", st.top().c_str());
            st.pop();
            if (!st.empty()) printf(" ");
        }
        puts("]");
    }
public:
    bool isValidSerialization(string preorder) {
        if (preorder.back() != '#') return false;
        stack<string> st;
        string s = "";
        for (char ch : preorder) {
            if (ch == ',') {
                if (!s.empty()) st.push(s);
                s = "";
            } else if (ch == '#') {
                st.push("#");
                f(st);
            } else {
                s += ch;
            }
            // printStack(st);
        }
        
        return st.size() == 1 && st.top() == "#";
    }
};
