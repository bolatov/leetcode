class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend());
        list<int> li;
        for (int i : deck) {
            if (!li.empty()) {
                li.push_front(li.back());
                li.pop_back();
            }
            li.push_front(i);
        }
        vector<int> vi(deck.size());
        int sz = 0;
        for (int i : li) {
            vi[sz] = i;
            sz++;
        }
        return vi;
    }
};
