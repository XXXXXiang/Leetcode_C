/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
        struct ListNode* ansHead = NULL;
        int buffer = 0;
        int l1_num = 0;
        int l2_num = 0;
        struct ListNode* cur = ansHead;
        do{
            struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
            l1_num = (l1? l1->val:0);
            l2_num = (l2? l2->val:0);
            new_node->val = (l1_num + l2_num + buffer)%10;
            //printf("new_node->val: %d\n",new_node->val);
            new_node->next = NULL;
            buffer = (l1_num + l2_num + buffer)/10;
            if (!ansHead){
                ansHead = new_node;
                cur = ansHead;
            }
            else{
                cur->next=new_node;
                cur = cur->next;
            }
            l1= (l1? l1->next:l1);
            l2= (l2? l2->next:l2);
        }while(l1!=NULL || l2!=NULL || buffer!=0);
        return ansHead;
}
