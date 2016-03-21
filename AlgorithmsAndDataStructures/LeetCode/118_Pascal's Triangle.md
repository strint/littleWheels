# Problem
118 Pascal's Triangle https://leetcode.com/problems/pascals-triangle/

# Analysis

# Solution
```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(0 == numRows) {
            return ret;
        }
        vector<int>* nv;
        nv = new vector<int>;
        nv->push_back(1);
        ret.push_back(*nv);
        if(1 == numRows) {
            return ret;
        }
        nv = new vector<int>;
        nv->push_back(1);
        nv->push_back(1);
        ret.push_back(*nv);
        if(2 == numRows) {
            return ret;
        }
        for(int i = 2; i < numRows; ++i) {
            nv = new vector<int>;
            for(int j = 0; j <= i; ++j) {
                if(j == 0 || j == i) {
                    nv->push_back(1);
                } else {
                    nv->push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
                }
            }
            ret.push_back(*nv);
        }
        return ret;

    }
};
```

# Notes
