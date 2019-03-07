class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int t = target - numbers[i];
            int lo = i + 1, hi = numbers.size() - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (numbers[mid] == t) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] < t) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return {};
    }
};
