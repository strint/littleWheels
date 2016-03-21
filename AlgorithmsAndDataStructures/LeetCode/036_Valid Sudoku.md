# Problem
Valid Sudoku https://leetcode.com/problems/valid-sudoku/

# Analysis

# Solution
```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r = board.size();
        int c = board.size();
        unordered_set<char> s;
        char n;
        //判断行合法
        for(int i = 0; i < r; ++i) {
            s.clear();
            for(int j = 0; j < c; ++j ) {
                n = board[i][j];
                if(n != '.') {
                    if(s.find(n) == s.end()) {
                        s.insert(n);
                    } else {
                        return false;
                    }
                }
            }
        }
        //判断列合法
        for(int i = 0; i < r; ++i) {
            s.clear();
            for(int j = 0; j < c; ++j ) {
                n = board[j][i];
                if(n != '.') {
                    if(s.find(n) == s.end()) {
                        s.insert(n);
                    } else {
                        return false;
                    }
                }
            }
        }
        //判断块合法
        for(int i = 0; i < r; i += 3) {
            for(int j = 0; j < c; j += 3 ) {
                s.clear();
                for(int k = 0; k < 3; ++k) {
                    for(int l = 0; l < 3; ++l) {
                        n = board[i + k][j + l];
                        if(n != '.') {
                            if(s.find(n) == s.end()) {
                                s.insert(n);
                            } else {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
```

# Notes
