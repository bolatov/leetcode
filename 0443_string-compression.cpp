class Solution {
public:
    int f(int i) {
        int len = 0;
        while (i) {
            len++;
            i /= 10;
        }
        return len;
    }
    int convert(vector<char>& chars, int i, int cnt, int sz) {
        int len = f(cnt);
        string w = to_string(cnt);
        int j = i + 1;
        for (char ch : w) chars[j++] = ch;

        int off = cnt - 1 - len;
        for (j = i + cnt; j < sz; j++) {
            chars[j - off] = chars[j];
        }
        return off;
    }
    int compress(vector<char>& chars) {
        int cnt = 1;
        int sz = chars.size();
        for (int i = chars.size() - 1; i > 0; i--) {
            if (chars[i] == chars[i - 1]) {
                cnt++;
                continue;
            } 
            
            if (cnt == 1) continue;
            
            sz -= convert(chars, i, cnt, sz);
            cnt = 1;
        }
        if (cnt > 1) 
            sz -= convert(chars, 0, cnt, sz);
        return sz;
    }
};
