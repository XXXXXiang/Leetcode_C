/*
86. Partition List
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* head1 = NULL;
    struct ListNode* pre1 = NULL;
    struct ListNode* head2 = NULL;
    struct ListNode* pre2 = NULL;
    for(struct ListNode* ptr = head;ptr!=NULL;ptr=ptr->next){
        if (ptr->val < x){
            if (head1 == NULL){
                head1 = ptr;
                pre1 = head1;
            }
            else{
                pre1->next = ptr;
                pre1 = ptr;
            }    
        }
        else{
            if (head2 == NULL){
                head2 = ptr;
                pre2 = head2;
            }
            else{
                pre2->next = ptr;
                pre2 = ptr;
            }
        }
    }
    if (pre1 != NULL && pre2!=NULL){
        pre1->next = head2;
        pre2->next = NULL;
        return head1;
    }
    else if (pre1 != NULL && pre2 == NULL)
        return head1;
    else if (pre1 == NULL && pre2 != NULL)
        return head2;
    else
        return head1;
}
