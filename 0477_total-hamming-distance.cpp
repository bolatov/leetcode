class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int cnt = 0;
        
        int highestBit = -1;
        for (int i : nums) {
            int h = 0;
            while (i >>= 1) {
                h++;
            }
            highestBit = max(highestBit, h);
        }
        // printf("highestBit = %d\n", highestBit);
        
        int n = nums.size();
        for (int b = 0; b <= highestBit; b++) {
            int a = 0;
            for (int i : nums) {
                a += (i & (1 << b)) > 0;
            }
            
            // printf("bit %d is set in %d numbers\n", b, a);
            cnt += (n - a) * a;
        }
        
        return cnt;
    }
};
