#include <bits/stdc++.h>

using namespace std;

class Stack {
private:
    queue<int> q;

public:
    // Push element x onto stack.
    void push(int x) { q.push(x); }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> t;
        while (q.size() > 1) {
            t.push(q.front());
            q.pop();
        }
        if (!q.empty()) {
            q.pop();
        }
        while (!t.empty()) {
            q.push(t.front());
            t.pop();
        }
    }

    // Get the top element.
    int top() {
        queue<int> t;
        while (q.size() > 1) {
            t.push(q.front());
            q.pop();
        }
        int tp = -1;
        if (!q.empty()) {
            tp = q.front();
            t.push(q.front());
            q.pop();
        }
        while (!t.empty()) {
            q.push(t.front());
            t.pop();
        }
        return tp;
    }

    // Return whether the stack is empty.
    bool empty() { return q.empty(); }
};

int main() {
    Stack st;
    for (int i = 1; i <= 10; ++i) {
        st.push(i);
    }

    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}