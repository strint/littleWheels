# Problem
61 Rotate List https://leetcode.com/problems/rotate-list/

# Solution
```cpp
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(NULL == head || 0 == k) {
            return head;
        }
        //思路：
        //1、找到要翻转的位置：使用两个指针，一个在前，一个在后，相距k，当在前面指针的走到链表末尾时，后面的指针就走到了要翻转的位置了
        //2、翻转
        
        //处理len < k的情况
        ListNode* p0 = head;
        int len = 1;
        while(p0->next != NULL) {
            p0 = p0->next;
            len++;
        }
        if(len < k) {
            k = k % len;
        }
        
        //找到翻转位置
        ListNode* p1;
        ListNode* p2;
        p1 = head;
        p2 = head;
        int dis = 0;
        while(p2->next != NULL) {
            p2 = p2->next;
            if(dis < k) {
                dis++;
            } else {
                p1 = p1->next;
            }
        }

        
        if(dis < k) {
            return head;
        }
        
        //翻转
        p2->next = head;
        head = p1->next;
        p1->next = NULL;

        return head;
    }
};
```

# Notes
