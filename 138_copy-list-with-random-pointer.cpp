/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> mp;
        RandomListNode * chead = new RandomListNode(head->label);
        mp[head] = chead;
        auto onode = head;
        auto cnode = chead;
        while (onode->next) {
            RandomListNode * cnxt = new RandomListNode(onode->next->label);
            cnode->next = cnxt;
            
            mp[onode->next] = cnxt;
            onode = onode->next;
            cnode = cnode->next;
        }
        
        onode = head;
        cnode = chead;
        while (onode) {
            if (onode->random) {
                cnode->random = mp[onode->random];
            }
            
            onode = onode->next;
            cnode = cnode->next;
        }
        return chead;
    }
};
