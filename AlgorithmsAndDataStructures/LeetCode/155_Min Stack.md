# Problem
155 Min Stack https://leetcode.com/problems/min-stack/

# Analysis

# Solution
```cpp
class MinStack {
    stack<int> s;
    stack<int> m;
public:
    void push(int x) {
        s.push(x);
        if(m.empty() || x < m.top()) {
            m.push(x);
        } else {
            m.push(m.top());
        }
    }

    void pop() {
        s.pop();
        m.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return m.top();
    }
};
```

# Notes
