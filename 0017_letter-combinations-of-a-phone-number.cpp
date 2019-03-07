class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dl = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
        };
        queue<string> q;
        q.push("");
        vector<string> v;
        for (int i = 0; i < digits.size(); i++) {
            int d = (int) (digits[i] - '0');
            queue<string> q2;
            while (!q.empty()) {
                string s = q.front();
                //printf("%s\n", s.c_str());
                q.pop();
                for (char ch : dl[d]) {
                    if (i == digits.size() - 1) {
                        v.push_back(s + ch);
                    } else {
                        q2.push(s + ch);
                    }
                }
            }
            q = q2;
        }
        return v;
    }
};
