/**
 * Defition for singly-linked list.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {


        int count = 0;
        //Handle if one of given linked list is Null.
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        
        if (l1->val < l2->val) { //Make sure we can start by l2.
            ListNode *temp = l1; //If l2->val is smaller, then exchange their name.
            l1 = l2;
            l2 = temp;
        }
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* current = l2;
        ptr2 = l2->next;

        while(true){// Stop condition is in the next line, once one pointer is found to be NULL.
            if (ptr1 == NULL || ptr2==NULL){// If one of ptr1 and ptr2 hit NULL, then point the current node to another linked list, and get result.
                printf("ptr2: %d\n",ptr2);
                if (ptr1 == NULL)
                    current->next = ptr2;
                else
                    current->next = ptr1;
                break;
            }
            
            else{
                if (ptr1->val > ptr2->val){
                    current->next = ptr2;
                    current = ptr2;
                    ptr2 = ptr2->next;
                }
                else{
                    current->next = ptr1;
                    current = ptr1;
                    ptr1 = ptr1->next;
                }
            }
        }
        return l2;
    }
};
