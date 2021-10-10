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
    ListNode* reverseList(ListNode* head) {
        ListNode* nodeA = head;
        ListNode* nodeB = NULL;
        ListNode* nodeC = NULL;
        bool firstCycle=true;
        /*
        nodeA -> nodeB -> nodeC
        Save nodeC address, then change nodeB's next.
        nodeA <- nodeB    nodeC
        Then, shift them.
        */
        
        //Handle the case if the length of linked list is less then 3.
        if (nodeA != NULL)
            nodeB = nodeA->next;
        else
            return nodeA;
        if (nodeB!=NULL)
            nodeC = nodeB->next;
        else
            return nodeA;
        if (nodeC==NULL){
            nodeA->next = NULL;
            nodeB->next = nodeA;
            return nodeB;
        }
        
        while (true){
            if (firstCycle){// If nodeC = NULL, means we can return nodeB as head of new linked list.
                nodeA->next = NULL;
                firstCycle = false;
            }
            //Shift nodeA, nodeB and nodeC.
            nodeB->next = nodeA;
            nodeA = nodeB;
            nodeB = nodeC;
            nodeC = nodeC->next;
            if (nodeC == NULL){
                nodeB->next = nodeA;
                return nodeB;
            }
        }
    }
};
