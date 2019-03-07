class Solution {
private:
    void printStack(stack<int> st) {
        while(!st.empty()) {
            cout << "\t" << st.top() << endl;
            st.pop();
        }
        cout << "-------------------------------\n";
    }
    void append(stack<int>& st, int n, char sign) {
        // printf("append %c%d", sign, n);
        switch(sign) {
            case '-':
                n *= -1;
            case '+':
                st.push(n);
                break;
            default:
                int top = st.top();
                st.pop();
                int k = sign == '*' ? top * n : top / n;
                st.push(k);
                break;
        }
    }
public:
    int calculate(string s) {
        stack<int> st;
        char sign = '+';
        int tmp = 0;
        for (char ch : s) {
            switch(ch) {
                case '-':
                case '*':
                case '/':
                case '+':
                    append(st, tmp, sign);
                    sign = ch;
                    tmp = 0;
                    break;
                case ' ':
                    break;
                default:
                    tmp *= 10;
                    tmp += (int) (ch - '0');
                    break;
            }
        }
        append(st, tmp, sign);
        // printStack(st);
        int ans = st.top();
        st.pop();
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
