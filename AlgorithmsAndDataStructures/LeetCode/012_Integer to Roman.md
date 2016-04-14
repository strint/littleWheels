# Problem
12 Integer to Roman

# Analysis

# Solution
```cpp
class Solution {
public:
    string intToRoman(int num) {
        string r = "MDCLXVI";
        vector<int> n = {1000, 500, 100, 50, 10, 5, 1};
        int count = 0;
        int p = 0;
        while(num / n[p] == 0) {
            ++p;
        }
        string ret = "";
        while(num > 0) {
            //算某个字母的个数
            count = 0;
            while(num - n[p] >= 0) {
                num -= n[p];
                ++count;
            }
            //添加字母到结果中
            if(4 == count) {
                //两种情况，一种是为9时，一种是为4时
                if(ret.back() == r[p- 1]) {
                    ret.pop_back();
                    ret += r[p];
                    ret += r[p - 2];
                } else {
                    ret += r[p];
                    ret += r[p - 1];
                }
            } else {
                for(int i = 0; i < count; ++i) {
                    ret += r[p];
                }
            }
            //开始算下一个字母的个数
            ++p;
        }
        return ret;
    }
};


/*
//我采用的递归的思路是经典的算法思考方法，具体这个问题，这种列举的思路真是很不错（发现了数制的特点）
class Solution {
    public:
        string intToRoman(int num) {
            static const string s[4][10]= 
            { 
                {"","I","II","III","IV","V","VI","VII","VIII","IX"},
                {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                {"","M","MM","MMM"},
            };

            return s[3][num/1000%10] + s[2][num/100%10] + s[1][num/10%10] + s[0][num%10];
        }
    };
*/
```

# Notes
