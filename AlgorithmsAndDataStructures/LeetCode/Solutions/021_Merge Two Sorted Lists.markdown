# Problem
Merge Two Sorted Lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* m;
        ListNode* n;
        ListNode* s1p;
        ListNode* s2p;
        ListNode s1(0), s2(0), s3(0); //构造三个节点，这样可以统一处理链表为空的情况
        s1.next = l1;
        s2.next = l2;
        s1p = &s1;
        s2p = &s2;
        m = &s3;
        n = &s3; //m的末尾节点
        //当两个链表都不为空时，将头小的那个加到m的末尾
        while(s1p->next != NULL && s2p->next != NULL) {
            if(s1p->next->val < s2p->next->val) {
                n->next = s1p->next; //m中的最后一个节点指向新添加的节点
                n = s1p->next; //n指向新的最后一个节点
                s1p->next = s1p->next->next; //在原链表中移除这个节点
            } else {
                n->next = s2p->next; //m中的最后一个节点指向新添加的节点
                n = s2p->next; //n指向新的最后一个节点
                s2p->next = s2p->next->next; //在原链表中移除这个节点
            }
        }
        //当一个链表为空，另一个链表不为空时，将不为空的链表直接加到m末尾
        if(s1p->next != NULL) {
            n->next = s1p->next;
        } else if(s2p->next != NULL) {
            n->next = s2p->next;
        }
        //当两个链表都为空时，返回合并的结果
        return m->next;
    }
};

/*
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
*/
```

# Notes
* 使用了链表伪头部的技巧
* 后面的注释的代码是别人的实现，思路完全相同，简洁很多
