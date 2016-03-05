# Problem
Add Two Numbers in linked list.数字逆序存储在链表中，实现两个数字的加法。https://leetcode.com/problems/add-two-numbers/

# Solution
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        int sum = 0, r = 0, c = 0;
        
        //first digit
        sum = l1->val + l2->val;
        if(sum < 10) {
            r = sum;
            c = 0;
        } else {
            r = sum % 10;
            c = sum / 10;
        }
        result->val =  r;
        
        ListNode* nodeBefore = result;
        ListNode* l1p = l1->next;
        ListNode* l2p = l2->next;
        
        //rest digits
        while(l1p != NULL || l2p != NULL) {
            if(l1p != NULL && l2p != NULL) {
                sum = c + l1p->val + l2p->val;
                l1p = l1p->next;
                l2p = l2p->next;
            } else if(l1p != NULL && l2p == NULL) {
                sum = c + l1p->val;
                l1p = l1p->next;
            } else if(l1p == NULL && l2p != NULL) {
                sum = c + l2p->val;
                l2p = l2p->next;
            }
            
            if(sum < 10) {
                r = sum;
                c = 0;
            } else {
                r = sum % 10;
                c = sum / 10;
            }
            
            ListNode* newNode = new ListNode(r);
            nodeBefore->next = newNode;
            nodeBefore = newNode;
        }

        if(c > 0) {
            ListNode* newNode2 = new ListNode(c);
            nodeBefore->next = newNode2;
        }

        
        return result;
    }
};
```

# Notes
* 加法的形式化，加数加上被加数，得到的和，超过10的，会有进位（这是会有商和余数）
* 对链表的遍历，主要是如何处理链表的开头和结尾
