/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) return true;
        }
        return false;

    }
};
        // ListNode* temp = head;

        // while(temp != NULL){

        //     if(temp->next == NULL) return false;
        //     temp = temp->next;
        // }
        // return true;
        