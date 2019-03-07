class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int en = size - 1;
        while (en >= 0) {
            // count number of occurrences of nums[en]
            int cnt = 1;
            for (int r = en - 1; r >= 0 && nums[r] == nums[en]; r--) {
                cnt++;
            }
            
            // check if nums[en] appears allowed (less than 2) number of times
            if (cnt <= 2) {
                en -= cnt;
                continue;
            }
            
            // at this point we know that nums[en] appears more than twice,
            // do a left shift
            int offset = cnt - 2;
            for (int r = en - 1; r < size; r++) {
                nums[r - offset] = nums[r];
            }
            
            // update variables
            en -= cnt;
            size -= cnt - 2;
        }
        
        return size;
    }
};
