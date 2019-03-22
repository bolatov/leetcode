// 304ms, 312.2mb
class Solution {
private:
    vector<vector<string>> ans;
    vector<string> vs;
    string str;
    bool isPalindrome(int be, int en) {
        if (be == en) return false;
        int lo = be, hi = en - 1;
        while (lo < hi) {
            if (str[lo] != str[hi])
                return false;
            lo++;
            hi--;
        }
        return true;
    }
    void search(int be, int en) {
        if (en == str.size()) {
            if (be == en) {
                ans.push_back(vs);
            } else if (isPalindrome(be, en)) {
                vs.push_back(str.substr(be, en - be));
                ans.push_back(vs);
                vs.pop_back();
            }
            return;
        }
        
        if (isPalindrome(be, en)) {
            vs.push_back(str.substr(be, en - be));
            search(en, en + 1);
            vs.pop_back();
        }
        search(be, en + 1);
    }
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return ans;
        str = s;
        search(0, 0);
        return ans;
    }
};

// 16ms, 15.3mb
class Solution {
private:
    vector<vector<string>> ans;
    vector<string> vs;
    string str;
    bool isPalindrome(int be, int en) {
        if (be == en) return false;
        int lo = be, hi = en - 1;
        while (lo < hi) {
            if (str[lo] != str[hi])
                return false;
            lo++;
            hi--;
        }
        return true;
    }
    void search(int be, int en) {
        if (en == str.size()) {
            if (be == en) {
                ans.push_back(vs);
            } else if (isPalindrome(be, en)) {
                vs.push_back(str.substr(be, en - be));
                ans.push_back(vs);
                vs.pop_back();
            }
            return;
        }
        
        if (isPalindrome(be, en)) {
            vs.push_back(str.substr(be, en - be));
            search(en, en + 1);
            vs.pop_back();
        }
        search(be, en + 1);
    }
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return ans;
        str = s;
        search(0, 0);
        return ans;
    }
};
