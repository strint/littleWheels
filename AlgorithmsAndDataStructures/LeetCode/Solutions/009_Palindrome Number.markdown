# Problem
Palindrome Number(回文数字)

# Solution
```
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || ((x != 0) && ((x % 10) == 0))) {
            return false;
        } else {
            int r = 0;
            int len = 0;
            //这里的判断很巧妙，包含了4种情况
            //1、x长度为偶数，边界情况是x和sum长度相同时：如果x == r，则跳出while，return true；如果此时x < r，跳出while，return false；如果此时 x > r；则x减一位、r加一位后，x一定小于r，这是return false
            //2、x长度为奇数时，边界情况是x比r多一位，这时x一定大于r，于是可以x移一位给r，然后x一定小于r，这时判断x == (r / 10)
            while(x > r) {
                 r = r * 10 + x % 10;
                 x /= 10;
            }
            return ((x == r)||(x == (r / 10)));
        }
    }
};
```

# Notes
* 代码的实现和分析的过程有些距离，可以认为是在正确答案的基础上做了优化吧，代码结构简单了很多，这样的代码只能用巧妙来形容了
