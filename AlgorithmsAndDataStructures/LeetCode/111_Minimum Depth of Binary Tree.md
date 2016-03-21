# Problem
111 Minimum Depth of Binary Tree https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        } else {
            int l = minDepth(root->left);
            int r = minDepth(root->right);
            if(l == 0 && r == 0) {
                return 1; //叶子节点
            } else if(l > 0 && r > 0) {
                return 1 + min(l, r);
            } else {
                return 1 + max(l, r); //某个节点的一个子树为空，另一个不为空时，为空的不是叶子节点,所以取大的
            }
        }
    }
};
```

# Notes
