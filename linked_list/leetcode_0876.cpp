/*
876. Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
https://leetcode.com/problems/middle-of-the-linked-list/
*/

/*Description for singly-linked list.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* mid = head;
        int even = true;
        if (head->next == NULL)
            return mid;
        for(ListNode* cur = head->next;cur!=NULL;cur=cur->next){
            if (even)
                mid = mid->next;
            even = !even;
        }
        return mid;
    }
};
