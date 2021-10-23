/*
203. Remove Linked List Elements

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
https://leetcode.com/problems/remove-linked-list-elements/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* ptr = head;
    struct ListNode* temp = NULL;
    while(ptr!=NULL){
        if(ptr == head && head->val == val){//If head is the target, then move head and ptr to next.
            temp = head;
            head = ptr->next;
            ptr=ptr->next;
            free(temp);
        }
            
        else if(ptr->next != NULL && ptr->next->val == val){//If next one is the target, then link the current node to next next one.
            temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
        }     
        else
            ptr=ptr->next;
    }
    return head;
}
