/*
160. Intersection of Two Linked Lists

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* ptrA = headA;
    struct ListNode* ptrB = headB;
    int lenA = 0;
    int lenB = 0;
    while(!(ptrA==NULL && ptrB==NULL)){ //Decide the lenth of linked list A and B.
        if(ptrA!=NULL){
            lenA+=1;
            ptrA=ptrA->next;
        }
            
        if(ptrB!=NULL){
            lenB+=1;
            ptrB=ptrB->next;
        }
    }
    
    //Take steps forward if it's a longer linked list. To align the begining.
    if (lenA >= lenB){
        for(int i = lenA - lenB;i!=0;i--){
            headA = headA->next;
        }
    }
    else{
        for(int i = lenB - lenA;i!=0;i--){
            headB = headB->next;
        }
    }
    
    //Step forowrd together.
    ptrA = headA;
    ptrB = headB;
    while(ptrA!=NULL && ptrB!=NULL){
        if(ptrA == ptrB)
            return ptrA;
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    return NULL;
}
