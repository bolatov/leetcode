class Solution {
  public:
    string intToRoman(int num) {
        string s = "";
        for (int i = 0; i < num / 1000; i++) {
            s += "M";
        }
        num %= 1000;

        if (num >= 900) {
            s += "CM";
            num %= 100;
        }

        if (num >= 500) {
            s += "D";
            num -= 500;
        }

        if (num >= 400) {
            s += "CD";
            num %= 100;
        }

        for (int i = 0; i < num / 100; i++) {
            s += "C";
        }
        num %= 100;

        if (num >= 90) {
            s += "XC";
            num %= 10;
        }

        if (num >= 50) {
            s += "L";
            num -= 50;
        }

        if (num >= 40) {
            s += "XL";
            num %= 10;
        }

        for (int i = 0; i < num / 10; i++) {
            s += "X";
        }
        num %= 10;

        if (num >= 9) {
            s += "IX";
            num %= 1;
        }

        if (num >= 5) {
            s += "V";
            num -= 5;
        }

        if (num >= 4) {
            s += "IV";
            num %= 1;
        }

        for (int i = 0; i < num; i++) {
            s += "I";
        }

        return s;
    }
};