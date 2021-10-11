/*
83. Remove Duplicates from Sorted List

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
https://leetcode.com/problems/remove-duplicates-from-sorted-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = head;
        //handle if head or head->next is NULL.
        if (head == NULL)
            return head;
        
        else if (head->next == NULL)
            return head;
        //Compare previous one and current one, if equally, then point previoust node to next node.
        //If not equally, then move the previous node to current node.
        for(ListNode* cur=head->next;cur!=NULL;cur=cur->next){
            if (pre->val==cur->val){
                pre->next = cur->next;
            }
            else
                pre = cur;
        }
        return head;
    }
};
