/*
234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome.
https://leetcode.com/problems/palindrome-linked-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode* head){
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast && fast->next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
       
    struct ListNode* pre = slow;
    struct ListNode* cur = slow->next;
    struct ListNode* ptrnext = NULL;
    
    while(cur){ //Reverse the linked list after mid-point. A->B->C<-B<-A
        ptrnext = cur -> next;
        cur->next = pre;
        pre = cur;
        cur = ptrnext;   
    }
    
    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = pre; //tail

    if(ptr1==ptr2) //If there is only one node, always return true.
        return true;
    
    while (true){
        if(ptr2->val != ptr1->val)
            return false;
        if (ptr2==slow)
            break;
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }
    return true;
}
