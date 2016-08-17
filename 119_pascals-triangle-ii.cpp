class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vi = {1, 1};
        vector<int> ui(rowIndex+1);
        if (rowIndex <= 0) vi = {1};
        for (int i = 2; i <= rowIndex; i++) {
            ui[0] = 1;
            ui[i] = 1;
            for (int j = 1; j < i; j++) {
                ui[j] = vi[j] + vi[j-1];
            }
            vi = ui;
        }
        return vi;
    }
};
