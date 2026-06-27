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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
        
    }
};
        // if(head == NULL || head->next == NULL) return head;

        // vector <int> lst;

        // ListNode* temp = head;
        // while(temp != NULL && temp->next != NULL){
        //     lst.push_back(temp->val);
        //     temp = temp->next->next;
        // }
        // if(temp !=NULL) lst.push_back(temp->val);

        // temp = head->next;
        //  while(temp != NULL && temp->next != NULL){
        //     lst.push_back(temp->val);
        //     temp = temp->next->next;
        // }
        // if(temp !=NULL) lst.push_back(temp->val);

        // temp = head;
        
        // for(int i = 0 ; i<lst.size() ; i++){
        //     temp->val = lst[i];
        //     temp = temp->next;
        // }

        // return head;