class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5) {
                five++;
                continue;
            } 
            
            if (bill == 10) {
                if (five <= 0) {
                    return false;
                }
                ten++;
                five--;
                continue;
            }
            
            if (ten > 0 && five > 0) {
                ten--;
                five--;
                continue;
            }
            
            if (five >= 3) {
                five -= 3;
                continue;
            }
            return false;
        }
        return true;
    }
};
