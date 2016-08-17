#include <stack>
#include <iostream>

using namespace std;

class MinStack {
  private:
    stack<pair<int, int>> st;

  public:
    void push(int x) {
        if (st.empty()) {
            st.push({x, x});
        } else {
            st.push({x, min(x, st.top().second)});
        }
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }

    bool empty() { return st.empty(); }
};

int main() {
    MinStack ms;
    for (int i = 1; i <= 10; i++) {
        ms.push(i);
    }

    while (!ms.empty()) {
        cout << ms.top() << " " << ms.getMin() << endl;
        ms.pop();
    }

    return 0;
}