# Problem
104 Maximum Depth of Binary Tree https://leetcode.com/problems/maximum-depth-of-binary-tree/

# Analysis

# Solution
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(NULL == root) {
            return 0;
        } else {
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
    }
};
```

# Notes
