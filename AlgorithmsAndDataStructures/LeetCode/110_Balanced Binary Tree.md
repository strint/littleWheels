# Problem
110. Balanced Binary Tree 

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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) {
            return true;
        } else {
            return (abs(maxDepth(root->left) - maxDepth(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
        }
    }
};
```

# Notes
