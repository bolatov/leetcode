class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for (int i = 0; i < bits.size();) {
            if (i == bits.size() - 1) {
                return !bits[i];
            }
            
            if (bits[i] == 1) {
                i += 2;
            } else {
                i++;
            }
        }
        
        return false;
    }
};
