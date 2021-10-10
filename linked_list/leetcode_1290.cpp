/*
1290. Convert Binary Number in a Linked List to Integer

Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.

https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
*/

/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        ListNode* ptr = NULL;
        for (ptr = head; ptr != NULL; ptr = ptr->next)
            result = result * 2 + ptr->val;
        return result;
    }
};
