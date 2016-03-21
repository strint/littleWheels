# Problem
107. Binary Tree Level Order Traversal II https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(NULL == root) {
            return ret;
        }
        int now, next, c;
        
        deque<TreeNode*> dq;
        dq.push_back(root);
        
        vector<int>* nv = new vector<int>;
        nv->push_back(root->val);
        ret.push_back(*nv);
        
        now = 1;
        c = 0;
        next = 0;
        TreeNode* nd;
        nv = new vector<int>;
        while(dq.size() > 0) {
            nd = dq.front();
            if(c == now) {
                //新的一层了
                now = next;
                next = 0;
                c = 0;
                ret.push_back(*nv);
                nv = new vector<int>;
                
            }
            if(nd->left != NULL) {
                dq.push_back(nd->left);
                nv->push_back(nd->left->val);
                ++next;
            }
            if(nd->right != NULL) {
                dq.push_back(nd->right);
                nv->push_back(nd->right->val);
                ++next;
            }
            ++c;
            dq.pop_front();
        }
        reverse(ret.begin(), ret.end());
        return ret;

    }
};
```

# Notes
