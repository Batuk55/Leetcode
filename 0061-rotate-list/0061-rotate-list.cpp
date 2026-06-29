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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0) return head;
        if(head==NULL || head->next == NULL) return head;

        ListNode* temp = head;
        int count = 1;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        temp->next = head;
        k = k % count;
        int thatNode = count-k;// k=3

        temp = head;
        while(thatNode>1){
            temp = temp->next;
            thatNode--;
        }
        ListNode* front = temp->next;
        temp->next = nullptr;
        return front;

    }
};