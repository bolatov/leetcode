#include <iostream>
#include <stack>

using namespace std;

class Queue {
  private:
    int front;
    stack<int> st, buf;

  public:
    // Push element x to the back of queue.
    void push(int x) {
        if (st.empty()) {
            front = x;
        }
        st.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while (!st.empty()) {
            buf.push(st.top());
            st.pop();
        }
        if (!buf.empty()) {
            buf.pop();
        }
        if (!buf.empty()) {
            front = buf.top();
        }
        while (!buf.empty()) {
            st.push(buf.top());
            buf.pop();
        }
    }

    // Get the front element.
    int peek(void) { return front; }

    // Return whether the queue is empty.
    bool empty(void) { return st.empty(); }
};

int main() {
    Queue q;
    for (int i = 1; i <= 10; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        printf("%d\n", q.peek());
        q.pop();
    }
    return 0;
}