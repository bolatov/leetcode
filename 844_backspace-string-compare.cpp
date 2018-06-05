class Solution {
public:
    void run(string S, stack<char>& s) {
        for (char ch : S) {
            if (ch == '#') {
                if (!s.empty()) s.pop();
            } else s.push(ch);
        }
    }
    bool backspaceCompare(string S, string T) {
        stack<char> s, t;
        run(S, s);
        run(T, t);
        while (!s.empty() && !t.empty()) {
            if (s.top() != t.top()) return false;
            s.pop();
            t.pop();
        }
        return s.empty() && t.empty();
    }
};
