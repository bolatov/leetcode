class Solution {
private:
    int binarySearch(vector<int>& nums, int target, bool findLeftMost) {
        int lo = 0;
        int hi = nums.size() - 1;
        int most = findLeftMost ? INT_MAX : INT_MIN;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                if (findLeftMost) {
                    most = min(mid, most);
                    hi = mid - 1;
                } else {
                    most = max(mid, most);
                    lo = mid + 1;
                }
                
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return 0 <= most && most < nums.size() ? most : -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        
        return {left, right};
    }
};
