# Problem
101 Symmetric Tree https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode* root) {
        //非递归的版本，用队列实现广度优先
        deque<TreeNode*> le;
        deque<TreeNode*> ri;
        if(root == NULL) {
            return true;
        } else {
            if(root->left == NULL && root->right == NULL) {
                return true;
            } else if(root->left != NULL && root->right != NULL) {
                if(root->left->val != root->right->val) {
                    return false;
                } else {
                    le.push_back(root->left);
                    ri.push_back(root->right);
                }
            } else {
                return false;
            }
        }
        TreeNode* ln;
        TreeNode* rn;
        while(le.size() > 0 && ri.size() > 0) {//判断左右树是否遍历完了
            //取左树的左右节点、右树的右左节点，比较是否相同
            ln = le.front();
            rn = ri.front();//在这里把ri写成了le，结果找了好久的bug，醉了。写得时候不能分神啊，这种笔误的bug，编译时看不出的话，真是很花时间
            //判断子节点是否相同
            //将子节点加入队列
            if(ln->left == NULL && rn->right == NULL) {
                //do nothing
            } else if(ln->left != NULL && rn->right != NULL) {
                if(ln->left->val != rn->right->val) {
                    return false;
                } else {
                    le.push_back(ln->left);
                    ri.push_back(rn->right);
                }
            } else {
                return false;
            }
            
            if(ln->right == NULL && rn->left == NULL) {
                //do nothing
            } else if(ln->right != NULL && rn->left != NULL) {
                if(ln->right->val != rn->left->val) {
                    return false;
                } else {
                    le.push_back(ln->right);
                    ri.push_back(rn->left);
                }
            } else {
                return false;
            }
            
            //当这个节点的左右节点都判断完了之后，从队列中去掉这个节点
            le.pop_front();
            ri.pop_front();
        }
        //当左右子树都判断完了，并且相同后
        return true;
    }
};


/*
//一个递归的版本、实际是深度优先
bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isSymmetric_helper(root->left, root->right);
}
bool isSymmetric_helper(TreeNode* root1, TreeNode* root2) {
    if (root1==NULL && root2==NULL) return true;
    if (root1==NULL || root2==NULL) return false;
    if (root1->val != root2->val) return false;
    return isSymmetric_helper(root1->left, root2->right) && isSymmetric_helper(root1->right, root2->left);
}
*/
```

# Notes
