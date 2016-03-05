# Problem
Two Sum，数组中是否存在两个数，这个两个数的和为某个特定值。

# Solution
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> exist;
        for(int i = 0; i < nums.size(); ++i) {
            exist[nums.at(i)] = i + 1;
        }
        for(int j = 0; j < nums.size(); ++j) {
            int want = target - nums.at(j);
            if(exist[want] && j + 1 != exist[want]) {
                result.push_back(j + 1);
                result.push_back(exist[want]);
                return result;
            }
        }
    }
};
```

# Notes
* 使用[map](http://en.cppreference.com/w/cpp/container/map)能够快速确定一个键值是否存在（map通常是用红黑树实现的，近似一个平衡二叉树，查找的时间复杂度是O(lgn)）
* 更快的是使用hash_map，在stl中，对应的数据结构是[unordered_set](http://en.cppreference.com/w/cpp/container/unordered_set)
