# LeeCode Solutions

## Bit Manipulation
https://leetcode.com/tag/bit-manipulation/

## Greedy
https://leetcode.com/tag/greedy/

## Sort
https://leetcode.com/tag/sort/

## Binary Search
https://leetcode.com/tag/binary-search/

## Tree
https://leetcode.com/tag/tree/

## BFS
https://leetcode.com/tag/breadth-first-search/

## DFS
https://leetcode.com/tag/depth-first-search/

## Stack
https://leetcode.com/tag/stack/

## Backtracking
https://leetcode.com/tag/backtracking/

## Dynamic Programming
https://leetcode.com/tag/dynamic-programming/

## Two Pointers
https://leetcode.com/tag/two-pointers/
* 标记起始位置
 * 3 https://leetcode.com/problems/longest-substring-without-repeating-characters/ （某符号对应的指针可以记录在map中，用基数排序的方式放在数组中）
 * 75 https://leetcode.com/problems/sort-colors/ （标记起始位置，根据标记的起始位置进行交换排序，这里类似快排的partion算法）
 * 88 https://leetcode.com/problems/merge-sorted-array/

* 求和，两个往中间移动的指针（组合问题，按照一定的规律移动，减少组合方式）
 * 11 https://leetcode.com/problems/container-with-most-water/ （水的挡板要提高）
 * 15 https://leetcode.com/problems/3sum/ （三个指针，其中一个遍历，另外两个往中间移动；排序可以使得遍历有序，减少遍历的数量）
 * 16 https://leetcode.com/problems/3sum-closest/ （类似于15）
 * 125 https://leetcode.com/problems/valid-palindrome/

* 标记相同的字符的位置
 * 26 https://leetcode.com/problems/remove-duplicates-from-sorted-array/

* 两层循环
 * 28 https://leetcode.com/problems/implement-strstr/


## Linked List
https://leetcode.com/tag/linked-list/

* 判断空指针、链表尾部、在链表上遍历，求链表的长度
 * 2 https://leetcode.com/problems/add-two-numbers/
 * 109 https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

* 在起始位置添加节点（这样可以保证开头一定非空、且利于实现循环不变式）
 * 21 https://leetcode.com/problems/merge-two-sorted-lists/

*  对链表进行切分
 * 注意区分命名，虽然都是指针，但最好写明链表头节点指针head、链表尾部节点指针end、链表尾节点之前的节点的指针endbefore，链表迭代指针itr
 * 截取一个节点
 * 截取一段链表
 * 86 https://leetcode.com/problems/partition-list/
 * 92 https://leetcode.com/problems/reverse-linked-list-ii/

* 快慢指针（计数、奇偶数）
 * 109 https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

* 相距一定间隔往前移动的指针
 * 19 https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * 61 https://leetcode.com/problems/rotate-list/

* 翻转 reverse
 * 24 https://leetcode.com/problems/swap-nodes-in-pairs/
 * 61 https://leetcode.com/problems/rotate-list/
 * 翻转 + 归并 143 https://leetcode.com/problems/reorder-list/

* 去重、相同节点计数
 * 82 https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * 83 https://leetcode.com/problems/remove-duplicates-from-sorted-list/

* 复制链表
 * 138 https://leetcode.com/problems/copy-list-with-random-pointer/

* 链表上的环
 * 环的判定，快慢指针 141 https://leetcode.com/problems/linked-list-cycle/
 * 得到环的节点 142 https://leetcode.com/problems/linked-list-cycle-ii/

* 归并链表
 * 21 https://leetcode.com/problems/merge-two-sorted-lists/

* 排序
 * 归并 148 https://leetcode.com/problems/sort-list/https://leetcode.com/problems/sort-list/
 * 插入 147 https://leetcode.com/problems/insertion-sort-list/
