/*
328. Odd Even Linked List

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode* curodd = head;
    struct ListNode* preodd = head;
    struct ListNode* cureven = head;
    struct ListNode* preeven = head;
    struct ListNode* evenhead = head;
    
    if (head!=NULL){
        cureven = head->next;
        preeven = head->next;
        evenhead = head->next;
    }
    
    while(cureven != NULL && cureven->next != NULL){
        curodd = curodd->next->next;
        cureven = cureven->next->next;
        if(curodd != head){
            preodd->next = curodd;
            preeven->next = cureven;
        }
        preodd = curodd;
        preeven = cureven;
    }
    if (head!=NULL)
        curodd->next = evenhead;
    return head;
}
