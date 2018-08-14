class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        
        for (int i = 0; i < haystack.size(); i++) {
            bool found = true;
            int j = 0;
            int k = i;
            while (k < haystack.size() && j < needle.size()) {
                if (haystack[k] != needle[j]) {
                    found = false;
                    break;
                }
                k++;
                j++;
            }
            
            if (found && j == needle.size()) {
                return i;
            }
        }
        
        return -1;
    }
};
