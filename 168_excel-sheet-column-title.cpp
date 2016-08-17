#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    string convertToTitle(int n) {
        if (n < 1) return "";

        string s = "";
        int mx = 26;
        for (; n; n /= mx) {
            if (n % mx == 0) {
                s += 'Z';
                n--;
            } else
                s += n % mx - 1 + 'A';
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    int n = 79;
    Solution s;
    cout << s.convertToTitle(n) << endl;
    return 0;
}