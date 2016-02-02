# Problem
Valid Parentheses

# Solution
```
class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) {
            return true;
        } else {
            stack<char> st;
            st.push(s.at(0));
            for(int i = 1; i < s.size(); ++i) {
                char c;
                if(st.size() == 0) { //此处存在st为空的可能
                    c = ' ';
                } else {
                    c = st.top();
                }
                char n = s.at(i);
                if((c == '(' && n == ')') || (c == '[' && n == ']') || (c == '{' && n == '}')) {
                    st.pop();
                } else {
                    st.push(s.at(i));
                }
            }
            if(st.size() == 0) {
                return true;
            } else {
                return false;
            }
        }
    }
};
```

# Notes
