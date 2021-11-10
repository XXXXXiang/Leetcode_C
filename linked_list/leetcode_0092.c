/*
92. Reverse Linked List II
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* pre = head;
    struct ListNode* cur = head;
    struct ListNode* nex = NULL;
    struct ListNode* leftN = head;
    struct ListNode* leftNpre = head;
    
    if (left==right)
        return head;
    
    for(int i = 1;i<=right;i++){
        nex = cur->next;
        if (i >= left+1)
            cur->next = pre;
        if (i==left)
            leftN = cur;
        else if (i==left-1)
            leftNpre = cur;
        pre = cur;
        cur = nex;
    }
    if (left == 1)
        head = pre;
    else
        leftNpre->next = pre;
    leftN->next = cur;
    
    return head;
}
