# Problem
Plus One https://leetcode.com/problems/plus-one/

# Analysis

# Solution
```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        int p = digits.size() - 1;
        while(carry && p >= 0) {
            if(digits.at(p) == 9) {
                digits[p] = 0;
                --p;
            } else {
                digits[p] += 1;
                carry = false;
                --p;
                return digits;
            }
        }
        if(carry && p == -1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
```

# Notes
