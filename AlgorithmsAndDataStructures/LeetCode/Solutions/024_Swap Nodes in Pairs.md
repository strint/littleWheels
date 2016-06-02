# Problem
24 Swap Nodes in Pairs https://leetcode.com/problems/swap-nodes-in-pairs/

# Analysis

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
    ListNode* swapPairs(ListNode* head) {
        ListNode h(0);
        h.next = head;
        ListNode * p1, *p2, *p3;
        p1 = &h;
        while(p1 != NULL && p1->next != NULL && p1->next->next != NULL) {
            //p2、p3分别指向要交换的两个节点
            p2 = p1->next;
            p3 = p2->next;
            
            //进行交换
            p1->next = p3;
            p2->next = p3->next;
            p3->next = p2;
            
            //p1指向要交换的两个节点之前的那个节点
            p1 = p2;
        }
        return h.next;
    }
};
```

# Notes
