/*
1721. Swapping Nodes in a Linked List

You are given the head of a linked list, and an integer k.
Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapNodes(struct ListNode* head, int k){
    struct ListNode* ptrfast = head;
    struct ListNode* ptrslow = head;
    for(int i =1;i<k;i++){
        ptrfast = ptrfast->next;
    }
    struct ListNode* front = ptrfast;
    
    while(ptrfast->next!=NULL){
        ptrfast = ptrfast->next;
        ptrslow = ptrslow->next;
    }
    struct ListNode* back = ptrslow;
    
    //swap
    int temp = front->val;
    front->val = back->val;
    back->val = temp;
    return head;
}
