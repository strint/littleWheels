# Problem
67. Add Binary https://leetcode.com/problems/add-binary/

# Analysis

# Solution
```
class Solution {
public:
    string addBinary(string a, string b) {
        string re = "";
        int ai, bi, carry, an, bn, sum;
        ai = a.size() - 1;
        bi = b.size() - 1;
        carry = 0; //进位
        while(ai > -1 || bi > -1) {
            //取数
            if(ai > -1) {
                an = a[ai] - '0';
            } else {
                an = 0;
            }
            if(bi > -1) {
                bn = b[bi] - '0';//之前在这里把bi写成了ai，看了半个小时才发现错误。。。
            } else {
                bn = 0;
            }
            
            //加法运算
            sum = an + bn + carry;
            if(sum == 0) {
                carry = 0;
                re.insert(0, "0");
            } else if(sum == 1) {
                carry = 0;
                re.insert(0, "1");
            } else if(sum == 2) {
                carry = 1;
                re.insert(0, "0");
            } else if(sum == 3) {
                carry = 1;
                re.insert(0, "1");
            }
            
            --ai;
            --bi;
        }
        //处理最后的一个进位
        if(carry == 1) {
            re.insert(0, "1");
        }
        return re;
    }
};
```

# Notes
