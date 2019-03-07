/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            NestedInteger ni(stoi(s.substr(0)));
            return ni;
        }
        
        NestedInteger ans;
        stack<NestedInteger> st;
        for (int i = 0; i < s.size();) {
            if (s[i] == '[') {
                NestedInteger l;
                st.push(l);
                i++;
            } else if (s[i] == ']') {
                ans = st.top();
                st.pop();
                if (!st.empty()) st.top().add(ans);
                i++;
            } else if (s[i] == ',') {
                i++;
            } else {
                size_t p1 = s.find(",", i);
                size_t p2 = s.find("]", i);
                size_t p = (p1 != string::npos && p1 < p2) ? p1 : p2;
                int val = stoi(s.substr(i, p - i));
                NestedInteger ni(val);
                st.top().add(ni);               
                i = s[p] == ']' ? p : p + 1;
            }
        }
        
        return ans;
    }
};
