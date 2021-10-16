/*
237. Delete Node in a Linked List

Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.
It is guaranteed that the node to be deleted is not a tail node in the list.
https://leetcode.com/problems/delete-node-in-a-linked-list/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void deleteNode(struct ListNode* node) {
    for(struct ListNode* ptr = node;ptr!=NULL;ptr=ptr->next){ //Move value instead of removing node.
        ptr->val=ptr->next->val;
        if (ptr->next->next==NULL)
            ptr->next=NULL;
    }
}
