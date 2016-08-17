class Solution {
private:
    int binarySearch(vector<int>& v, int lo, int hi, int t) {
        int mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (v[mid] == t) {
                return mid;
            } else if (v[mid] < t) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& v, int t) {
        int n = v.size();
        int lo = 0, hi = v.size() - 1, mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            printf("mid = %d\n", mid);
            if (mid + 1 < n && v[mid] > v[mid+1]) {
                mid++;
                break;
            } else if (mid + 1 == n && v[mid] > v[0]) {
                break;
            } else if (mid - 1 >= 0 && v[mid-1] > v[mid]) {
                break;
            } else if (v[mid] < v[mid+1] && v[lo] < v[mid]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return max(binarySearch(v, 0, mid - 1, t), binarySearch(v, mid, n - 1, t));
    }
};
