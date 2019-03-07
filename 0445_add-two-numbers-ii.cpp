/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    stack<int> fill(ListNode* l) {
        stack<int> st;
        while (l) {
            st.push(l->val);
            l = l->next;
        }
        return st;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1 = fill(l1);
        stack<int> st2 = fill(l2);
        
        // NOTE!
        // This code does not work unless
        // sum is initialized to NULL.
        ListNode* sum = NULL;
        
        int q = 0;
        while (!st1.empty() && !st2.empty()) {
            int t1 = st1.top();
            int t2 = st2.top();
            st1.pop();
            st2.pop();
            
            int k = t1 + t2 + q;
            q = k / 10;
            k %= 10;
            
            auto nxt = new ListNode(k);
            nxt->next = sum;
            sum = nxt;
        }
        
        for (auto s = st1.empty() ? st2 : st1; !s.empty(); s.pop()) {
            int k = s.top() + q;
            q = k / 10;
            k %= 10;

            auto nxt = new ListNode(k);
            nxt->next = sum;
            sum = nxt;
        }
        
        if (q > 0) {
            auto nxt = new ListNode(q);
            nxt->next = sum;
            sum = nxt;
        }
        
        return sum;
    }
};
