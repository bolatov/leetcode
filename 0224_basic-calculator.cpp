class Solution {
private:
    void printStack(stack<int> st, string offset) {
        printf("%s:", offset.c_str());
        while (!st.empty()) {
            printf(" %d", st.top());
            st.pop();
        }
        printf("\n");
    }
    void shrink(stack<int>& st) {
        while(st.size() >= 2) {
            int top = st.top();
            st.pop();
            
            int nextTop = st.top();
            st.pop();
            
            st.push(top + nextTop);
        }
    }
    
    void clearStack(stack<int>& st) {
        while (!st.empty()) st.pop();
    }
    
    void applySign(stack<int>& st, int sign, string offset) {
        if (!st.empty()) {
            // printf("%sapplySign: top=%d sign=%d\n", offset.c_str(), st.top(), sign);
            int top = st.top();
            st.pop();
            st.push(top * sign);
        }
    }
    
    int calc(stack<int>& st, string s, int i, string offset) {
        // printf("%sstart i=%d\n", offset.c_str(), i);
        int n = 0;
        int sign = 1;
        bool closeBracket = false;
        int oldTop = 0;
        for (; i < s.size() && !closeBracket; i++) {
            char ch = s[i];
            switch(ch) {
                case '-':
                    st.push(n * sign);
                    n = 0;
                    sign = -1;
                    break;
                case '+':
                    st.push(n * sign);
                    n = 0;
                    sign = 1;
                    break;
                case '(':
                    oldTop = st.empty() ? 0 : st.top();
                    clearStack(st);
                    i = calc(st, s, i + 1, "  " + offset);
                    applySign(st, sign, offset);
                    // printf("%safterBrackets: oldTop=%d brackets=%d\n", offset.c_str(), oldTop, st.top());
                    st.push(oldTop);
                    n = 0;
                    sign = 1;
                    break;
                case ')':
                    // printf("%scloseBracket: n=%d sign=%d\n", offset.c_str(), n, sign);
                    st.push(n * sign);
                    n = 0;
                    closeBracket = true;
                    break;
                case ' ':
                    break;
                default:
                    n *= 10;
                    n += (int) (ch - '0');
                    break;
            }
            // printStack(st, offset + string(1, ch));
            shrink(st);
        }
        // printf("%send i=%d top=%d\n", offset.c_str(), i, st.top());
        return i - 1;
    }
public:
    int calculate(string s) {
        stack<int> st;
        calc(st, "(" + s + ")", 0, "");
        return st.top();
    }
};
