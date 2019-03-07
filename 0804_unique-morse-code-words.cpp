class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;
        vector<string> vs = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",
            ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
            "...","-","..-","...-",".--","-..-","-.--","--.."};
        for (string s : words) {
            string t = "";
            for (char ch : s) {
                t += vs[(int) (ch - 'a')];
            }
            st.insert(t);
        }
        return st.size();
    }
};