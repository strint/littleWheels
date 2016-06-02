# Problem
112 Path Sum https://leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) {
            return false;
        } else {
            return dfs(root, 0, sum);
        }
    }
    bool dfs(TreeNode* root, int i, int sum) {
        if(root->left == NULL && root->right == NULL){
            //叶节点
            if(i + root->val == sum) {
                return true;
            } else {
                return false;
            }
        } else if(root->left != NULL && root->right != NULL) { //or tree
            return dfs(root->left, i + root->val, sum) || dfs(root->right, i + root->val, sum);
        } else if(root->left != NULL && root->right == NULL){
            return dfs(root->left, i + root->val, sum);
        } else {
            return dfs(root->right, i + root->val, sum);
        }
        
    }
};


/*
bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val); //这个判断条件更简洁
    }
*/
```

# Notes
