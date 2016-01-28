# Problem
String to Integer (atoi)

# Solution
```
class Solution {
public:
    int myAtoi(string str) {
        long long int i = 0;
        char tempC;
        int tempI;
        int stage = 0;
        int sign = 1;
        for(int j = 0; j < str.size(); ++j) {
            tempC = str.at(j);
            //stage 0表示处理空格的阶段，1表示处理数字的阶段
            if(stage == 0  && tempC == ' ') {//处理空格
                
            } else if(stage == 0 && (tempC == '-' || tempC == '+')) {//处理正负号
                stage = 1;
                if(tempC == '-') sign = -1;
            } else if(stage == 0 && (tempC >= '0' && tempC <= '9')) {//处理无正负号的数字
                stage = 1;
                tempI = tempC - '0';
                i = tempI;
            } else if(stage == 0) {//处理空格的阶段遇到非空格、非正负号、非数字
                return 0;
            } else if(stage == 1 && (tempC >= '0' && tempC <= '9')) {//处理数字阶段遇到数字
                tempI = tempC - '0';
                if((i > (INT_MAX / 10) || (i == (INT_MAX / 10) && tempC > '6')) && sign == 1) { //达到正的上界
                    return INT_MAX;
                } else if((i > (INT_MAX / 10) || (i == (INT_MAX / 10) && tempC > '7')) && sign == -1) {//达到负的下界
                    return INT_MIN;
                } 
                i = i * 10 + tempI;
            } else if(stage == 1) {//处理数字阶段遇到非数字
                break;
            }
        }
        i = i * sign;
        return i;
    }
};
```

# Notes
* 重点在于处理溢出：在还未溢出时进行判断下一步是否会溢出
```
if((i > (INT_MAX / 10) || (i == (INT_MAX / 10) && tempC > '6')) && sign == 1) { //达到正的上界
    return INT_MAX;
} else if((i > (INT_MAX / 10) || (i == (INT_MAX / 10) && tempC > '7')) && sign == -1) {//达到负的下界
    return INT_MIN;
} 
```
