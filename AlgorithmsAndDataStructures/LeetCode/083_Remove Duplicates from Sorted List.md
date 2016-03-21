# Problem
83. Remove Duplicates from Sorted List https://leetcode.com/problems/remove-duplicates-from-sorted-list/
# Analysis

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* p1, *p2;
        p1 = head;
        p2 = head->next;
        while(p1) {
            if(p2 == NULL) {
                p1->next = p2;
                p1 = p2;
            } else if(p1->val == p2->val) {
                p2 = p2->next;
            } else {
                p1->next = p2;
                p1 = p2;
                p2 = p1->next;
            }
        }
        return head;
    }
};
```

# Notes
