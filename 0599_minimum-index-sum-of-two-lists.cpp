class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> vs;
        int iSum = INT_MAX;
        for (int i = 0; i < list1.size(); i++) {
            for (int j = 0; j < list2.size(); j++) {
                if (list1[i] == list2[j]) {
                    int idxSum = i + j;
                    if (idxSum < iSum) {
                        vs.clear();
                        vs.push_back(list1[i]);
                        iSum = idxSum;
                    } else if (idxSum == iSum) {
                        vs.push_back(list1[i]);
                    }
                }
            }
        }
        return vs;
    }
};
