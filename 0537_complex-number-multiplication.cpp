class Solution {
public:
    int getReal(string s) {
        int pos = s.find('+');
        string num = s.substr(0, pos);
        return stoi(num, 0, 10);
    }
    
    int getImaginary(string s) {
        int pos = s.find('+');
        string num = s.substr(pos + 1, s.size() - pos);
        return stoi(num, 0, 10);
    }
    
    string complexNumberMultiply(string n, string m) {
        int a = getReal(n);
        int b = getImaginary(n);
        
        int c = getReal(m);
        int d = getImaginary(m);
        
        int r = a * c + b * d * (-1);
        int i = a * d + b * c;
        
        return to_string(r) + "+" + to_string(i) + "i";
    }
};
