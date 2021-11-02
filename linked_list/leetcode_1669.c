/*
1669. Merge In Between Linked Lists

You are given two linked lists: list1 and list2 of sizes n and m respectively.
Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    int i = 0;
    struct ListNode* ptr1 = list1;
    struct ListNode* ptr2 = list2;
    struct ListNode* temp = NULL;
    struct ListNode* backpoint = NULL;
    bool movingPtr2 = false;
    bool movingPtr1 = true;
    while(ptr1!=NULL && ptr2!=NULL){
        if (ptr1->next != NULL && (i+1 == a)){
            temp = ptr1;
            ptr1 = ptr1->next;
            i++;
            temp->next = list2;
            movingPtr2 = true;
        }
        if (ptr1!=NULL && i == b){
            backpoint = ptr1->next;
            movingPtr1 = false;
        }
        if (ptr2->next == NULL){
            ptr2->next = backpoint;
            movingPtr1 = true;
            movingPtr2 = false;
        }
        if (movingPtr1){
            i++;
            ptr1 = ptr1->next;
        }
        if (movingPtr2)
            ptr2 = ptr2->next;
    }
    return list1;
}
