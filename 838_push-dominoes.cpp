class Solution {
public:
    string pushDominoes(string s) {
        vector<int> vl, vr;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') vl.push_back(i);
            else if (s[i] == 'R') vr.push_back(i);
        }
        
        int i = 0, j = 0;
        int begin = 0;
        while (i < vl.size() && j < vr.size()) {
            // Check if there is an 'R' coming before 'L'
            if (vr[j] < vl[i]) {
                // Find the right-most 'R' that comes before 'L'.
                int lo = j, hi = vr.size() - 1;
                int k = j;
                while (lo <= hi) {
                    int mid = lo + (hi - lo) / 2;
                    if (vr[mid] < vl[i]) {
                        k = max(k, mid);
                        lo = mid + 1;
                    } else if (vr[mid] > vl[i]) {
                        hi = mid - 1;
                    }
                }
                               
                // Set all chars to 'R' between jth and kth indices;
                int be = vr[j], en = vr[k];
                while (be <= en) {
                    s[be++] = 'R';
                }
                j = k;
                
                // Run in opposite directions setting 'R'--> <--'L'
                be = vr[j], en = vl[i];
                begin = en + 1;
                while (be < en) {
                    s[be++] = 'R';
                    s[en--] = 'L';
                }
                i++;
                j++;
            } else {
                int be = begin, en = vl[i];
                begin = en + 1;
                while (be <= en) {
                    s[be++] = 'L';
                }
                i++;
            }
        }
        
        // Check if there are more 'L's
        if (i < vl.size()) {
            int en = vl[vl.size() - 1];
            while (en >= begin) {
                s[en--] = 'L';
            }
        }
        
        // Check if there are more 'R's
        if (j < vr.size()) {
            int be = vr[j];
            while (be < s.size()) {
                s[be++] = 'R';
            }
        }
        
        return s;
    }
};
