class Solution {
public:
    bool rotateString(string A, string B) {
        if (A == B) {
            return true;
        }
        return !A.empty() && !B.empty() &&
            B.size() >= A.size() && 
            (B + B).find(A) != string::npos;
    }
};
