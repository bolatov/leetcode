class Solution {
  public:
    // solved by looking at a formula
    // in Wiki
    int addDigits(int n) { return n - 9 * ((n - 1) / 9); }
};