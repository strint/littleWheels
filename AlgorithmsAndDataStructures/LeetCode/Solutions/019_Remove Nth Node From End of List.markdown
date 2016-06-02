# Problem
Remove Nth Node From End of List（移除链表倒数第n个元素）
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //思路是两个链表指针相错n步往前移动，当前面的指针移到链表尾部时，
        //后面的指针移动到了倒数第n+1个元素，这时删掉该指针后面的元素就好了
        
        //构造一个起始节点，这样方便统一处理n个节点，删除的也是倒数第n个节点的情况
        ListNode s(0);
        s.next = head;
        
        ListNode * p1;//前面的指针
        ListNode * p2;//后面的指针
        p1 = p2 = &s;
        if(head->next == NULL) {
            return NULL;
        } else {
            //前面的指针先往前移动n步
            for(int i = 1; i <=n; ++i) {
                p1 = p1->next;
            }
            //两个指针一起往前移动
            while(p1->next != NULL) {
                p1 = p1->next;
                p2 = p2->next;
            }
            //删除节点
            p2->next = (p2->next)->next;
            //返回结果
            return s.next;
        }
    }
};
```

# Notes
* 两个先后出发的指针能够以一定的间隔往前移动
* 添加一个人工节点，构造一个更通用的循环不变式，能够处理删除头节点的情况
