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
    ListNode* reverse(ListNode* head , int k){
        
        ListNode* temp = head;
        for(int i = 0; i<k; i++){
            if(temp == NULL) return head;
            temp = temp->next;
        }

        temp = head;
        ListNode* front = nullptr;
        ListNode* prev = nullptr;
        int cnt = 0;
        while(temp!=NULL && cnt<k){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
            cnt++;
        }
        head->next = reverse(temp , k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        head = reverse(head , k);



        return head;
    }
};